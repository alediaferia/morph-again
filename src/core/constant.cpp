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

std::unique_ptr<Value> Constant::toValue() const {
    std::ostringstream ss;
    if (token()->tag() == Token::NUM)
    	ss << "mov $" << std::static_pointer_cast<Num>(token())->value() << ", %eax";

    return std::unique_ptr<Value>(new Value(ss.str()));
}
