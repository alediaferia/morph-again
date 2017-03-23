//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "id.h"
#include <sstream>

Id::Id(std::shared_ptr<Word> id, std::shared_ptr<Type> t) : Expr(id, t) {

}

std::string Id::toString() const {
    std::ostringstream ss;
    ss << "Id(" << token()->toString() << "<" << type() ->toString() << ">)";
    return ss.str();
}

std::shared_ptr<Word> Id::id() const {
    return std::static_pointer_cast<Word>(token());
}
