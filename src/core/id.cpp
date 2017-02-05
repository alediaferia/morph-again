//
// Created by Alessandro Diaferia on 28/01/2017.
//

#include "id.h"

Id::Id(std::shared_ptr<Word> id, std::shared_ptr<Type> t, int bytes) : Expr(id, t),
    _offset(bytes) {

}