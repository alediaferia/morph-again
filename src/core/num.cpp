//
// Created by Alessandro Diaferia on 25/01/2017.
//

#include "num.h"
#include <sstream>

Num::Num(int value) : Token(Token::NUM),
  _value(value)
{}

Num::~Num() {}

std::string Num::toString() const {
    std::ostringstream ss;
    ss << "Num( " << _value << " )";
    return ss.str();
}

int Num::value() const {
	return _value;
}