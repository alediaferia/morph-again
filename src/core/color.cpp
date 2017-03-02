//
// Created by Alessandro Diaferia on 26/01/2017.
//

#include "color.h"

Color::Color(const std::string &c) : Word(c, Tag::HCOLOR) {
    // converting the string #aabb22 to 3 bytes
    _r = std::stoi(std::string(&c.c_str()[1], 2));
    _g = std::stoi(std::string(&c.c_str()[3], 2));
    _b = std::stoi(std::string(&c.c_str()[5], 2));
}
