#ifndef ELEMENT_H
#define ELEMENT_H

#include "attribute.h"

#include <list>

class Element {
public:
    Element();
    Element(const std::list<Attribute> &attributes);
    virtual ~Element();

    virtual void init();
protected:
};

#endif
