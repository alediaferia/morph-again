#include "parser.h"
#include "type.h"
#include "constant.h"
#include "assign.h"
#include "arith.h"

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
        ss << "Unexpected token '" << **_token << "' (expected '" << c << "')" << std::endl;
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

    std::shared_ptr<Node> node_;
    if (_token->tag() == Token::BASIC)
        node_ = decl();
    else
        node_ = expr();

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

// <decl> ::= (<basic-type> <id> [=<expr>] ';')*
std::shared_ptr<Node> Parser::decl() {
    if (_token->tag() == Token::BASIC) {
        std::shared_ptr<Type> t = type(); 
        std::shared_ptr<Token> tok = _token;
        TRY_MATCH_ELSE(Token::ID, nullptr);
        auto id = std::make_shared<Id>(std::static_pointer_cast<Word>(tok), t);
        std::shared_ptr<Node> node_;
        if (**_token == '=') { // inline assignment
            node_ = assignTo(id);
        } else {
            node_ = id;
        }

        TRY_MATCH_ELSE((char)';', nullptr);
        _scope->put(tok, id);

        return node_;
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
    case Token::ID:
    {
        auto word = std::dynamic_pointer_cast<Word>(_token);
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
