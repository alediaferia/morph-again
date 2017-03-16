#ifndef RET_H
#define RET_H

#include "stmt.h"
#include "expr.h"

class Ret : public Stmt {
public:
	Ret(std::shared_ptr<Expr> expr);

	std::string toString() const override;
private:
	std::shared_ptr<Expr> _expr;
};

#endif // RET_H
