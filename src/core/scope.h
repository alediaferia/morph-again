//
// Created by Alessandro Diaferia on 04/02/2017.
//

#ifndef SCOPE_H
#define SCOPE_H

#include <map>
#include "token.h"
#include "id.h"

class Scope {
public:
    Scope();
    Scope(std::weak_ptr<Scope> parent);
    ~Scope();

    void put(std::shared_ptr<Token> tok, std::shared_ptr<Id> id);
    std::shared_ptr<Id> get(std::shared_ptr<Token>);
private:
    std::map<std::shared_ptr<Token>, std::shared_ptr<Id>> _symbols;
    std::weak_ptr<Scope> _parent;
};


#endif // SCOPE_H
