//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include <iostream>
#include <sstream>
#include "arith.h"

Arith::Arith(std::shared_ptr<Token> tok, std::shared_ptr<Expr> x1,
             std::shared_ptr<Expr> x2) : Op(tok, nullptr),
_expr1(x1),
_expr2(x2) {
    auto t = Type::max(x1->type(), x2->type());
    if (!t) {
        std::cerr << "Error: unable to infer type from expressions " << x1->toString() << ", " << x2->toString() << std::endl;
    } else {
        setType(t);
    }
}

std::string Arith::toString() const {
    std::ostringstream ss;
    ss << "Arith("  << _expr1->toString() << " " << token()->toString() << " " << _expr2->toString() << ")";

    return ss.str();
}