#include "exprstmt.h"

#include <sstream>

ExprStmt::ExprStmt(std::shared_ptr<Expr> expr) : Stmt(),
    _expr(expr)
{}

std::shared_ptr<Expr> ExprStmt::expr() const {
    return _expr;
}

std::string ExprStmt::toString() const {
    std::ostringstream ss;
    ss << "Stmt (Expr): " << _expr->toString();
    return ss.str();
}

std::unique_ptr<Value> ExprStmt::toValue() const {
	return _expr->toValue();
}
