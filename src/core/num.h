//
// Created by Alessandro Diaferia on 25/01/2017.
//

#ifndef NUM_H
#define NUM_H

#include "token.h"

class Num : public Token {
public:
    Num(int value);
    ~Num();

    std::string toString() const;
private:
    const int _value;
};


#endif //MORPH_AGAIN_NUM_H
