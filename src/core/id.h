//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef ID_H
#define ID_H

#include "expr.h"

class Id : public Expr {
public:
    Id(std::shared_ptr<Word> id, std::shared_ptr<Type> t, int bytes);

private:
    int _offset;
};


#endif // ID_H
