#include "fn.h"

#include <sstream>

Fn::Fn(std::shared_ptr<Word> id,
	   const std::shared_ptr<Type> ret,
	   std::vector<std::shared_ptr<Id>> args, std::shared_ptr<Seq> seq) : Id(id, Type::Fn),
    _ret(ret),
    _args(args),
    _seq(seq)
{}

std::string Fn::toString() const {
	std::ostringstream ss;
	ss  << "fn " << id()->toString() << "(" <<_ret->toString() << ")" << "(";
	for (int i = 0; i < _args.size(); i++) {
		ss << _args[i]->toString() << ", ";
	}

	ss << ")";

	return ss.str();
}
