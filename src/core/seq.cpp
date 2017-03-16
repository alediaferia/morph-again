#include "seq.h"

#include <sstream>

Seq::Seq(std::shared_ptr<Stmt> s1, std::shared_ptr<Stmt> s2) : Stmt(),
    _s1(s1),
    _s2(s2)
{}

std::shared_ptr<Stmt> Seq::stmt1() const {
    return _s1;
}

std::shared_ptr<Stmt> Seq::stmt2() const {
    return _s2;
}

std::string Seq::toString() const {
	std::ostringstream ss;
	ss << "Seq(" << std::endl;
	ss << _s1->toString() << "," << std::endl;
	ss << _s2->toString() << std::endl;
	ss << ")";

	return ss.str();
}
