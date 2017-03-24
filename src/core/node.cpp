//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "node.h"

Node::Node() {

}

std::string Node::toString() const {
    return "<node>";
}

std::unique_ptr<Value> Node::toValue() const {
    return std::unique_ptr<Value>(new Value());
}