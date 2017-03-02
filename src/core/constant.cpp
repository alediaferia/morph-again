#include "constant.h"
#include "num.h"
#include <sstream>

Constant::Constant(std::shared_ptr<Token> tok, std::shared_ptr<Type> t) : Expr(tok, t) {

}

Constant::Constant(int i) : Expr(std::make_shared<Num>(i), Type::Int)
{}

std::string Constant::toString() const {
    std::ostringstream ss;
    ss << "Const " << token()->toString() << "<" << type()->toString() << ">)";
    return ss.str();
}