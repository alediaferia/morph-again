#include "decl.h"

#include <sstream>

Decl::Decl(std::shared_ptr<Id> id) : Stmt(),
_id(id)
{}

std::string Decl::toString() const {
	std::ostringstream ss;
	ss << "Decl( " << _id->toString() << " )";
	return ss.str();
}