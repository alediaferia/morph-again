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
    Scope(std::shared_ptr<Scope> parent);

    
    void put(std::shared_ptr<Token> tok, std::shared_ptr<Id> id);
    std::shared_ptr<Id> get(std::shared_ptr<Token>);

    void setParent(std::shared_ptr<Scope> parent);
    std::shared_ptr<Scope> parent() const;
private:
    std::map<std::shared_ptr<Token>, std::shared_ptr<Id>> _symbols;
    std::shared_ptr<Scope> _parent;
};


#endif // SCOPE_H
