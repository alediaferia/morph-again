//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "array.h"
#include <sstream>

Array::Array(int size, std::shared_ptr<Type> t) : Type("[]", Token::INDEX, size * t->width()),
  _of(t)
{}

std::string Array::toString() const {
    // <type>[ size ]

    std::ostringstream os;
    os << _of->toString() << "[ " << width() << " ]";

    return os.str();
}