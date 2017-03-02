#include "set.h"

Set::Set(std::shared_ptr<Id> id, std::shared_ptr<Expr> expr) : Stmt(),
    _id(id),
    _expr(expr)
{}

std::shared_ptr<Id> id() const {
    return _id;
}

std::shared_ptr<Expr> expr() const {
    return _expr;
}

