#ifndef STMT_H
#define STMT_H

#include "node.h"
#include <memory>

class Stmt : public Node {
public:
    static std::shared_ptr<Stmt> Null;
    Stmt();

    virtual std::string toString() const override;
};

#endif // STMT_H
