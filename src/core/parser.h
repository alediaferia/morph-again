#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "token.h"
#include "scope.h"
#include "stmt.h"
#include "decl.h"
#include "fn.h"
#include "ret.h"
#include "seq.h"

#include <memory>

class Parser {
public:
    Parser(std::unique_ptr<Lexer> lexer);

    void setInput(const std::string &input);

    // main
    std::shared_ptr<Node> program(bool newScope = true);

protected:
    // error reporting
    inline void error(const std::string &err);
    inline void undeclIdError(const std::string &id);
    inline void syntaxError(const std::string &err);

    // parsing
    void next();
    bool match(char c);
    bool match(Token::Tag);

    // lang
    std::shared_ptr<Expr> parenExpr();
    std::shared_ptr<Expr> expr();
    std::shared_ptr<Expr> term();
    std::shared_ptr<Stmt> stmt();
    std::shared_ptr<Expr> factor();
    std::shared_ptr<Ret> ret();
    std::shared_ptr<Seq> stmts();

    std::shared_ptr<Type> type();
    std::shared_ptr<Id> id();
    std::shared_ptr<Stmt> decl();
    std::shared_ptr<Fn> fn();
    std::shared_ptr<Stmt> block(std::shared_ptr<Scope> scope);

    std::shared_ptr<Stmt> assign();
    std::shared_ptr<Stmt> assignTo(std::shared_ptr<Id> id);

private:
    std::shared_ptr<Scope> _scope;
    std::unique_ptr<Lexer> _lexer;
    std::shared_ptr<Token> _token;

private:
    inline void failedMatch(std::string arg);
};

#endif // PARSER_H
