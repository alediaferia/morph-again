//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef  ARRAY_H
#define ARRAY_H


#include "type.h"

class Array : public Type {
public:
    Array(int size, std::shared_ptr<Type> t);

    virtual std::string toString() const;
private:
    std::shared_ptr<Type> _of;
};


#endif // ARRAY_H
