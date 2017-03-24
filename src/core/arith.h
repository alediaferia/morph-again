//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef ARITH_H
#define ARITH_H

#include "op.h"
#include "expr.h"

#include <memory>

class Arith : public Op {
public:
    Arith(std::shared_ptr<Token> tok,
          std::shared_ptr<Expr> x1, std::shared_ptr<Expr> x2);

    std::string toString() const override;

    std::unique_ptr<Value> toValue() const override;
private:
    std::shared_ptr<Expr> _expr1;
    std::shared_ptr<Expr> _expr2;
};


#endif // ARITH_H
