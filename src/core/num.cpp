//
// Created by Alessandro Diaferia on 25/01/2017.
//

#include "num.h"

Num::Num(int value) : Token(Token::NUM),
  _value(value)
{}

Num::~Num() {}

std::string Num::toString() const {
    static std::string str = std::to_string(_value);
    return str;
}