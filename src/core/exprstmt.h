#ifndef EXPRSTMT_H
#define EXPRSTMT_H

#include "stmt.h"
#include "expr.h"

class ExprStmt : public Stmt 
{
public:
    ExprStmt(std::shared_ptr<Expr> expr);

    std::shared_ptr<Expr> expr() const;

    std::string toString() const override;
private:
    std::shared_ptr<Expr> _expr;
};

#endif // EXPRSTMT_H
