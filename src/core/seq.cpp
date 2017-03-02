#include "seq.h"

Seq::Seq(std::shared_ptr<Stmt> s1, std::shared_ptr<Stmt> s2) : Stmt(),
    _s1(s1),
    _s2(s2)
{}

std::shared_ptr<Stmt> stmt1() const {
    return _s1;
}

std::shared_ptr<Stmt> stmt2() const {
    return _s2;
}

