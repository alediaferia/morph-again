#include "fn.h"

#include <sstream>

Fn::Fn(const std::string &identifier,
	   const std::shared_ptr<Type> ret,
	   std::vector<std::shared_ptr<Id>> args, std::shared_ptr<Seq> seq) : Stmt(),
    _identifier(identifier),
    _ret(ret),
    _args(args),
    _seq(seq)
{}

std::string Fn::toString() const {
	std::ostringstream ss;
	ss  << "fn " << _identifier << "(" <<_ret->toString() << ")" << "(";
	for (int i = 0; i < _args.size(); i++) {
		ss << _args[i]->toString() << ", ";
	}

	ss << ")";

	return ss.str();
}
