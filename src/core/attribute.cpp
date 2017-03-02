/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Attribute.cpp
 * Author: alediaferia
 * 
 * Created on 03 July 2016, 13:58
 */

#include "attribute.h"
#include <sstream>

Attribute::Attribute() {
}

Attribute::Attribute(const std::string &name, int value) :
    _name(name),
    _intValue(value),
    _valueType(Integer)
{}

Attribute::Attribute(const std::string &name, const std::string &value) :
    _name(name),
    _stringValue(value),
    _valueType(String)
{}

Attribute::~Attribute() {
}

int Attribute::intValue() const {
    return _intValue;
}

std::string Attribute::stringValue() const {
    return _stringValue;
}

std::string Attribute::name() const {
    return _name;
}

std::string Attribute::toString() const {
    std::ostringstream sStream;
    if (_valueType == Integer)
        sStream << "Attribute#" << this << "(name: " << _name << ", value: " << _intValue << ")";
    else if (_valueType == String)
        sStream << "Attribute#" << this << "(name: " << _name << ", value: \"" << _stringValue << "\")";

    return sStream.str();
}

