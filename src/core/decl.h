#ifndef DECL_H
#define DECL_H

#include "stmt.h"
#include "id.h"

class Decl : public Stmt {
public:
	Decl(std::shared_ptr<Id> id);

	virtual std::string toString() const override;

private:
	std::shared_ptr<Id> _id;
};

#endif // DECL