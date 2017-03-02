#include "symbol_table.h"

#include <mutex>

SymbolTable::SymbolTable()
{}

SymbolTable::~SymbolTable()
{}

void SymbolTable::push() {
    tables_.push(SymbolTable::Table());
}

void SymbolTable::pop() {
    tables_.pop();
}

void SymbolTable::add(const std::string& identifier,
                      const std::shared_ptr<Expression>& lval) {

    auto &t = tables_.top();
    t[identifier] = lval;
}

std::shared_ptr<Expression> SymbolTable::get(const std::string& identifier) const {
    auto &t = tables_.top();
    auto it = t.find(identifier);
    if (it == t.end()) {
        return std::shared_ptr<Expression>();
    }

    return it->second;
}

