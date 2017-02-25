#ifndef SET_H
#define SET_H

#include "expr.h"
#include "id.h"

// Represents an assignment
class Set : public Stmt {
public:
    Set(std::shared_ptr<Id> id, std::shared_ptr<Expr> expr);

    std::shared_ptr<Id> id() const;
    std::shared_ptr<Expr> expr() const;
private:
    std::shared_ptr<Id> _id;
    std::shared_ptr<Expr> _expr;
};

#endif // SET_H

