#include "stmt.h"

std::shared_ptr<Stmt> Stmt::Null = std::make_shared<Stmt>();

Stmt::Stmt() : Node() {
}

std::string Stmt::toString() const {
	return "Stmt()";
}
