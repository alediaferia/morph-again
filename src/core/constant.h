#ifndef CONSTANT_H
#define CONSTANT_H

#include "expr.h"
#include "token.h"
#include "type.h"
#include "value.h"

class Constant : public Expr {
public:
    Constant(std::shared_ptr<Token> tok, std::shared_ptr<Type> t);
    Constant(int i);

    std::string toString() const override;

    Value toValue() const override;
};
#endif // CONSTANT_H
