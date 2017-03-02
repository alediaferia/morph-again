#include "strlit.h"

StrLit::StrLit(const std::string &lit) : Word(lit, Token::STRLIT),
_length(lit.length()) {
}

int StrLit::length() const {
	return _length;
}
