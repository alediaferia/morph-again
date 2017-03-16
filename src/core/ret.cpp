#include "ret.h"
#include <sstream>

Ret::Ret(std::shared_ptr<Expr> expr) : Stmt(),
_expr(expr)
{}

std::string Ret::toString() const {
	std::ostringstream ss;
	ss << "return( " << _expr->toString() << ")";
	return ss.str();
}
