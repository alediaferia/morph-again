//
// Created by Alessandro Diaferia on 18/01/2017.
//

#include "value.h"

value::value(int value)
{
    _value += std::to_string(value);
}

value::~value() {}

std::string value::toString() const {
    return _value;
}
