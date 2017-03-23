#ifndef FN_H
#define FN_H

#include "expr.h"
#include "type.h"
#include "id.h"
#include "seq.h"

#include <string>
#include <vector>

class Fn : public Id {
public:
	Fn(std::shared_ptr<Word> id,
	   const std::shared_ptr<Type> ret,
	   std::vector<std::shared_ptr<Id>> args,
       std::shared_ptr<Seq> seq);

	virtual std::string toString() const override;

private:
	std::shared_ptr<Type> _ret;
	std::vector<std::shared_ptr<Id>> _args;
	std::shared_ptr<Seq> _seq;
};

#endif // FN_H
