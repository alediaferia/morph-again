//
// Created by Alessandro Diaferia on 16/01/2017.
//

#include "expression.h"

Expression::Expression(int number) :
    type_(Number),
    number_(number)
{
}

Expression::Expression(std::shared_ptr<Expression> lhs, int op, std::shared_ptr<Expression> rhs) :
        type_(Binary),
        op_(op),
        lhs_(lhs),
        rhs_(rhs)
{}

int Expression::numberValue() const {
    if (type_ == Number) {
        return number_;
    }

    switch(op_) {
        case '+':
            return lhs_->numberValue() + rhs_->numberValue();
        case '-':
            return lhs_->numberValue() - rhs_->numberValue();
        case '*':
            return lhs_->numberValue() * rhs_->numberValue();
        case '/':
            return lhs_->numberValue() / rhs_->numberValue();
    }
}