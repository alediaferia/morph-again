//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "op.h"
#include "temp.h"

Expr *Op::reduce() {
    Expr *expr = gen();
    Temp *t = new Temp(type());

    // TODO emit assignment
    // temp = expr(x) (e.g. t1 = 1 + 4)
    return t;
}
