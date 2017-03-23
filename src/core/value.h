#ifndef VALUE_H
#define VALUE_H

#include <string>

class Value {
public:
    Value();
    Value(const std::string &);

    virtual std::string toString() const;

private:
    std::string _value;
};

#endif // VALUE_H
