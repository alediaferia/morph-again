#include "assign.h"
#include <sstream>

Assign::Assign(std::shared_ptr<Id> id, std::shared_ptr<Expr> expr) : Stmt(),
_id(id),
_expr(expr) {

}

std::shared_ptr<Id> Assign::id() const {
    return _id;
}

std::shared_ptr<Expr> Assign::expr() const {
    return _expr;
}

std::string Assign::toString() const {
    std::ostringstream ss;
    ss << "Assign(" << _id->toString() << "," << _expr->toString() << ")";

    return ss.str();
}