#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <string>

class Printable {
public:
    virtual std::string toString() const = 0;
};
#endif // PRINTABLE_H
