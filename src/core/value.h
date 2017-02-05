//
// Created by Alessandro Diaferia on 18/01/2017.
//

#ifndef MORPH_AGAIN_VALUE_H
#define MORPH_AGAIN_VALUE_H

#include "printable.h"

class Value : Printable {
public:
    Value(int value);
    virtual ~Value();

    std::string toString() const override;

private:
    std::string _value;
};


#endif //MORPH_AGAIN_VALUE_H
