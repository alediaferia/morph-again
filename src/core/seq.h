#ifndef SEQ_H
#define SEQ_H

#include "stmt.h"

class Seq : public Stmt {
public:
    Seq(std::shared_ptr<Stmt> s1, std::shared_ptr<Stmt> s2);

    std::shared_ptr<Stmt> stmt1() const;
    std::shared_ptr<Stmt> stmt2() const
private:
    std::shared_ptr<Stmt> _s1;
    std::shared_ptr<Stmt> _s2;
};

#endif // SEQ_H

