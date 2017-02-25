//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "op.h"

Op::Op(std::shared_ptr<Token> tok, std::shared_ptr<Type> type) : Expr(tok, type)
{}