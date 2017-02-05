#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <memory>
#include <stack>
#include <map>
#include <string>

#include "expression.h"

class SymbolTable {
public:
    SymbolTable();
    ~SymbolTable();

    void push();
    void pop();

    void add(const std::string& identifier, const std::shared_ptr<Expression>& lval);
    std::shared_ptr<Expression> get(const std::string& identifier) const;

protected:

private:
typedef std::map<std::string,
        std::shared_ptr<Expression>> Table;
    std::stack<Table> tables_;
};
#endif
