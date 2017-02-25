//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "expr.h"
#include <sstream>

Expr::Expr(std::shared_ptr<Token> tok, std::shared_ptr<Type> t) : Node(),
  _token(tok),
  _type(t)
{

}

std::string Expr::toString() const {
    std::ostringstream ss;
    ss << "Expr(<" << _type->toString() << "> => " << _token->toString() << ")";
    return ss.str();
}

std::shared_ptr<Token> Expr::token() const {
    return _token;
}

std::shared_ptr<Type> Expr::type() const {
    return _type;
}

void Expr::setType(std::shared_ptr<Type> t) {
    _type = t;
}
