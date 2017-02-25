#ifndef ASSIGN_H
#define ASSIGN_H

#include "stmt.h"
#include "id.h"
#include "expr.h"

#include <memory>

class Assign : public Stmt {
public:
    Assign(std::shared_ptr<Id> id, std::shared_ptr<Expr> expr);

    std::shared_ptr<Id> id() const;
    std::shared_ptr<Expr> expr() const;

    std::string toString() const override;
private:
    std::shared_ptr<Id> _id;
    std::shared_ptr<Expr> _expr;
};

#endif // ASSIGN_H
