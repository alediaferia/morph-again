//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef TYPE_H
#define TYPE_H

#include "word.h"
#include <memory>
#include <string>

class Type : public Word {
public:
    Type(const std::string &s, Token::Tag, int w);
    int width() const;

    static std::shared_ptr<Type> Int;
    static std::shared_ptr<Type> Float;
    static std::shared_ptr<Type> Char;
    static std::shared_ptr<Type> Bool;
    static std::shared_ptr<Type> Void;

    static std::shared_ptr<Type> max(std::shared_ptr<Type> t1, std::shared_ptr<Type> t2);
    static bool isNumeric(std::shared_ptr<Type> t);
private:
    int _width;
};


#endif // TYPE_H
