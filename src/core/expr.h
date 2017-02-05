//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef EXPR_H
#define EXPR_H

#include "node.h"
#include "token.h"
#include "type.h"

class Expr : public Node {
public:
    Expr(std::shared_ptr<Token> tok, std::shared_ptr<Type> t);

    virtual Expr* gen();
    virtual Expr* reduce();

    std::string jump(int trueIndex, int falseIndex);

    virtual std::string toString() const;

    std::shared_ptr<Token> token() const;
    std::shared_ptr<Type> type() const;
protected:
    std::string emitJump(const std::string &test, int trueIndex, int falseIndex);

    void setType(std::shared_ptr<Type> t);
private:
    std::shared_ptr<Token> _token;
    std::shared_ptr<Type> _type;
};


#endif //MORPH_AGAIN_EXPR_H
