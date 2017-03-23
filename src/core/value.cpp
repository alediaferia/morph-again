#include "value.h"

Value::Value() : _value() {}

Value::Value(const std::string &value) :
_value(value)
{}

std::string Value::toString() const {
    return _value;
}