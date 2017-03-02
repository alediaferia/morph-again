//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "type.h"

std::shared_ptr<Type> Type::Int = std::shared_ptr<Type>(new Type("int", Token::BASIC, 4));
std::shared_ptr<Type> Type::Float = std::shared_ptr<Type>(new Type("float", Token::BASIC, 8));
std::shared_ptr<Type> Type::Char = std::shared_ptr<Type>(new Type("char", Token::BASIC, 1));
std::shared_ptr<Type> Type::Bool = std::shared_ptr<Type>(new Type("bool", Token::BASIC, 1));

Type::Type(const std::string &s, Token::Tag tag, int w) : Word(s, tag),
 _width(w) {
}

int Type::width() const {
    return _width;
}

bool Type::isNumeric(std::shared_ptr<Type> t) {
    if (t == Int || t == Float || t == Bool)
        return true;

    return false;
}

std::shared_ptr<Type> Type::max(std::shared_ptr<Type> t1, std::shared_ptr<Type> t2) {
    if (!isNumeric(t1) || !isNumeric(t2))
        return nullptr;
    else if (t1 == Float || t2 == Float)
        return Float;
    else if (t1 == Int || t2 == Int)
        return Int;
    else
        return Char;
}
