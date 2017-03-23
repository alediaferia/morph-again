#ifndef CALLEXPR_H
#define CALLEXPR_H

#include "expr.h"
#include "fn.h"

class CallExpr : public Expr {
public:
    CallExpr(std::shared_ptr<Fn>, std::vector<Expr> params);
};

#endif
