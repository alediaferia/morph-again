//
// Created by Alessandro Diaferia on 26/01/2017.
//

#ifndef COLOR_H
#define COLOR_H

#include "word.h"

class Color : public Word {
public:
    Color(const std::string &c);

private:
    char _r;
    char _g;
    char _b;
};


#endif //MORPH_AGAIN_COLOR_H
