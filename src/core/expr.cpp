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
    return _token->toString();
}

std::string Expr::emitJump(const std::string &test, int trueIndex, int falseIndex) {
    std::ostringstream str;
    if (trueIndex != 0 && falseIndex != 0) {
        str << "if " << test << " goto L" << trueIndex << std::endl;
        str << "goto L" << falseIndex;
    } else if (trueIndex != 0) {
        str << "if " << test << "goto L" << trueIndex;
    } else if (falseIndex != 0) {
        str << "iffalse " << test << "goto L" << falseIndex;
    }
    return emit(str.str());
}

std::string Expr::jump(int trueIndex, int falseIndex) {
    return emitJump(toString(), trueIndex, falseIndex);
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
