//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef OP_H
#define OP_H


#include "expr.h"

class Op : public Expr {
public:
    Op(std::shared_ptr<Token> tok, std::shared_ptr<Type> type);
};


#endif // OP_H
