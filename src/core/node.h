//
// Created by Alessandro Diaferia on 28/01/2017.
//

#ifndef NODE_H
#define NODE_H

#include <string>

#include "value.h"

class Node {
public:
    Node();

    std::string emitLabel(int index);
    std::string emit(const std::string &str);

    virtual std::string toString() const;

    virtual Value toValue() const;
};


#endif //MORPH_AGAIN_NODE_H
