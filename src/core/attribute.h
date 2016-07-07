/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Attribute.h
 * Author: alediaferia
 *
 * Created on 03 July 2016, 13:58
 */

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

#include "printable.h"

class Attribute : public Printable {
public:
    enum ValueType {
        Unknown = 0,
        Integer,
        String
    };
    Attribute();
    Attribute(const std::string &name, int value);
    // Attribute(const std::string &name, const std::string &value);
    virtual ~Attribute();
    
    int value() const;
    std::string name() const;

    std::string toString() const;

private:
    std::string _name;
    std::string _stringValue;
    int _intValue;
};

#endif /* ATTRIBUTE_H */

