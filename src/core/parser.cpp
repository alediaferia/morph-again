#include "parser.h"
#include "type.h"
#include "constant.h"
#include "assign.h"
#include "arith.h"
#include "strlit.h"
#include "array.h"
#include "seq.h"

#include <sstream>
#include <iostream>

#define TRY_MATCH(arg) \
    if (!match(arg)) \
        return;

#define TRY_MATCH_ELSE(arg, _else) \
    if (!match(arg)) \
        return _else;

Parser::Parser(std::unique_ptr<Lexer> lexer) : _lexer(std::move(lexer))
{
    _scope = std::make_shared<Scope>();
}

void Parser::setInput(const std::string &input) {
    _lexer->setSource(input.cbegin(), input.cend());
}

void Parser::error(const std::string &err) {
    std::cerr << err << std::endl;
}

void Parser::syntaxError(const std::string &err) {
   std::ostringstream ss; 
   ss << "Syntax error: " << err;
   error(ss.str());
}

void Parser::undeclIdError(const std::string &id) {
    std::ostringstream ss;
    ss << "Undeclared identifier '" << id << "'" << std::endl;
    error(ss.str());
}

void Parser::next() {
    _token = _lexer->scan();
}

bool Parser::match(Token::Tag tag) {
    if (_token->tag() != tag) {
        std::ostringstream ss;
        ss << "Unexpected token type '" << _token->tag() << "' (expected '" << tag << "')" << std::endl;
        syntaxError(ss.str());
        return false;
    }
    next();
    return true;
}

bool Parser::match(char c) {
    if (**_token != c) {
        std::ostringstream ss;
        ss << "Unexpected token '" << **_token << "' (" << _token->tag() << ")" << " (expected '" << c << "')" << std::endl;
        syntaxError(ss.str());
        return false;
    }
    next();
    return true;
}

// <program> ::= <expr>
std::shared_ptr<Node> Parser::program(bool newScope) {
    next();
    
    if (newScope) // pushing a new scope
        _scope = std::make_shared<Scope>(_scope);

    std::shared_ptr<Node> node_ = std::static_pointer_cast<Node>(stmts());

    if (newScope) // popping scope
        _scope = _scope->parent();
    return node_;
}

// // <func-decl> ::= 'fn' <identifier> '()' -> <type> <block>
// void Parser::funcDecl() {
// }

// // <block> ::= '{' (decls|stmts) '}'
// void Parser::block() {
//     TRY_MATCH('{');
//     // pushing a new scope
//     _scope = std::make_shared<Scope>(_scope);
//     // parsing declarations
//     decls();
//     // parsing statements
//     // TODO
    
//     // restoring scope
//     _scope = _scope->parent();
// }

// <decl> ::= <basic-type> <id> [=<expr>]
std::shared_ptr<Stmt> Parser::decl() {
    if (_token->tag() == Token::BASIC) {
        std::shared_ptr<Stmt> stmt;
        auto id_ = id();
        std::shared_ptr<Decl> decl_ = std::make_shared<Decl>(id_);
        if (**_token == '=') { // inline assignment
            auto assign = assignTo(id_);
            stmt = std::make_shared<Seq>(decl_, assign);
        } else {
            stmt = decl_;
        }

        _scope->put(id_->token(), id_);

        return stmt;
    } else if (_token->tag() == Token::FN) {
        return fn();
    }

    std::ostringstream ss;
    ss << "Unexpected '" << **_token << "' for declaration" << std::endl;
    error(ss.str());
    return nullptr;
}

std::shared_ptr<Type> Parser::type() {
    std::shared_ptr<Token> tok = _token;
    TRY_MATCH_ELSE(Token::BASIC, nullptr);
    return std::static_pointer_cast<Type>(tok); 
}

// <assign> ::= <id> '=' <expr>;
std::shared_ptr<Stmt> Parser::assign() {
    auto tok = _token;
    TRY_MATCH_ELSE(Token::ID, nullptr);
    auto id = _scope->get(tok);
    if (!id) {
        std::ostringstream ss;
        ss << "Undeclared identifier '" << **tok << "'" << std::endl;
        error(ss.str());
        return nullptr;
    }
    return assignTo(id);
}

std::shared_ptr<Stmt> Parser::assignTo(std::shared_ptr<Id> id) {
    TRY_MATCH_ELSE('=', nullptr);
    auto expr_ = expr();
    auto set = std::make_shared<Assign>(id, expr_);
    return set;
}

// <factor> ::= CONSTANT |
//              IDENT    |
//              <parenexpr>
std::shared_ptr<Expr> Parser::factor() {
    std::shared_ptr<Expr> expr;
    switch (_token->tag()) {
    case Token::NUM:
        expr = std::make_shared<Constant>(_token, Type::Int);
        next();
        break;
    case Token::STRLIT:
    {
        auto strlit = std::static_pointer_cast<StrLit>(_token);
        expr = std::make_shared<Constant>(_token, std::make_shared<Array>(strlit->length(), Type::Char));
        next();
        break;
    }
    case Token::ID:
    {
        auto word = std::static_pointer_cast<Word>(_token);
        auto identifier = word->toString();
        auto id = _scope->get(_token);
        if (!id) {
            undeclIdError(_token->toString());
        }
        next();
        return id;
    }
    case Token::OTHER:
    {
        if (**_token == '(') {
            expr = parenExpr();
        }
        next();
        break;
    }
    default:
        error("Syntax error");
    }

    return expr;
}

// <parenexpr> ::= '(' <expr> ')'
std::shared_ptr<Expr> Parser::parenExpr() {
    TRY_MATCH_ELSE('(', nullptr);
    auto expr_ = expr();
    TRY_MATCH_ELSE(')', nullptr);

    return expr_;
}

// <expr> ::= <term> ('+'|'-') <term>
std::shared_ptr<Expr> Parser::expr() {
    auto term_ = term();
    while (**_token == '+' || **_token == '-') {
        auto tok = _token;
        next();
        term_ = std::make_shared<Arith>(tok, term_, term());
    }

    return term_;
}

// <stmt> ::= (<decl> | <ret>) ';'
std::shared_ptr<Stmt> Parser::stmt() {
    std::shared_ptr<Stmt> node_;
    if (_token->tag() == Token::BASIC || _token->tag() == Token::FN) 
        node_ = decl();
    else if (_token->tag() == Token::RETURN)
        node_ = ret();
    else
        return Stmt::Null;

    TRY_MATCH_ELSE(';', nullptr);

    return node_;
}

// <term> ::= <factor> ('*'|'/') <factor>
std::shared_ptr<Expr> Parser::term() {
    auto factor_ = factor();
    while (**_token == '*' || **_token == '/') {
        auto tok = _token;
        next();
        factor_ = std::make_shared<Arith>(tok, factor_, factor());
    }

    return factor_;
}

// <fn> ::= 'fn' <identifier> '(' (<arg>[,<arg>])* ')' <block>
std::shared_ptr<Fn> Parser::fn() {
    TRY_MATCH_ELSE(Token::FN, nullptr);

    std::shared_ptr<Token> tok = _token;
    TRY_MATCH_ELSE(Token::ID, nullptr);
    auto fnId = std::static_pointer_cast<Word>(tok);

    TRY_MATCH_ELSE('(', nullptr);
    std::vector<std::shared_ptr<Id>> args;
    std::shared_ptr<Scope> fnScope = std::make_shared<Scope>(_scope);

    while (**_token != ')') {
        auto id_ = id();
        fnScope->put(id_->token(), id_);
        args.push_back(id_);
        if (**_token != ',')
            break;
    }
    TRY_MATCH_ELSE(')', nullptr);

    auto seq = block(fnScope);

    return std::make_shared<Fn>(fnId->toString(), Type::Void, args, std::static_pointer_cast<Seq>(seq));
}

std::shared_ptr<Id> Parser::id() {
    std::shared_ptr<Type> t = type();
    std::shared_ptr<Token> tok = _token;
    TRY_MATCH_ELSE(Token::ID, nullptr);
    return std::make_shared<Id>(std::static_pointer_cast<Word>(tok), t);
}

// <stmts> ::= <stmt>+
std::shared_ptr<Seq> Parser::stmts() {
    std::shared_ptr<Seq> seq_;
    auto stmt_ = stmt();
    if (stmt_ == Stmt::Null) {
        return std::make_shared<Seq>(stmt_, Stmt::Null);
    } else {
        return std::make_shared<Seq>(stmt_, stmts());
    }
}

// <block> ::= '{' <stmts> '}'
std::shared_ptr<Stmt> Parser::block(std::shared_ptr<Scope> scope) {
    TRY_MATCH_ELSE('{', nullptr)

    auto prevScope = _scope;
    if (scope)
        _scope = scope;

    auto block = stmts();
    _scope = prevScope;

    TRY_MATCH_ELSE('}', nullptr)

    return block;
}

// <return> ::= 'return' <expr>
std::shared_ptr<Ret> Parser::ret() {
    TRY_MATCH_ELSE(Token::RETURN, nullptr);

    return std::make_shared<Ret>(expr());
}
