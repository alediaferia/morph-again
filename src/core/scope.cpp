//
// Created by Alessandro Diaferia on 04/02/2017.
//

#include "scope.h"

Scope::Scope() {

}

Scope::Scope(std::shared_ptr<Scope> parent) : _parent(parent) {

}

void Scope::put(std::shared_ptr<Token> tok, std::shared_ptr<Id> id) {
    _symbols[tok] = id;
}

std::shared_ptr<Id> Scope::get(std::shared_ptr<Token> tok) {
    auto *scope = this;
    while (scope) {
        auto it = scope->_symbols.find(tok);
        if (it != scope->_symbols.end()) {
            return it->second;
        }
        if (!scope->_parent) {
            return nullptr;
        }
        scope = scope->_parent.get();
    }

    return nullptr;
}

std::shared_ptr<Scope> Scope::parent() const {
    return _parent;
}

void Scope::setParent(std::shared_ptr<Scope> scope) {
    _parent = scope;
}
