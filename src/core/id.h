//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef ID_H
#define ID_H

#include "expr.h"

class Id : public Expr {
public:
    Id(std::shared_ptr<Word> id, std::shared_ptr<Type> t);

    std::string toString() const override;

    std::shared_ptr<Word> id() const;
private:
};


#endif // ID_H
