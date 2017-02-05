//
// Created by Alessandro Diaferia on 04/02/2017.
//

#include "scope.h"

Scope::Scope() {

}

Scope::Scope(std::weak_ptr<Scope> parent) : _parent(parent) {

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
        auto p = scope->_parent.lock();
        if (!p) {
            return nullptr;
        }
        scope = p.get();
    }
}
