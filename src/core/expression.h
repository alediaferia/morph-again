//
// Created by Alessandro Diaferia on 16/01/2017.
//

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <memory>

class Expression {
public:

    enum Type {
        Number,
        String,
        Identifier,
        Binary
    };

    //Expression(const std::string &identifier, bool literal = false);
    Expression(int number);
    Expression(std::shared_ptr<Expression> lhs, int op, std::shared_ptr<Expression> rhs);

    int numberValue() const;

private:
    int op_;
    std::shared_ptr<Expression> lhs_;
    std::shared_ptr<Expression> rhs_;
    Type type_;
    int number_;
};

#endif // EXPRESSION_H
