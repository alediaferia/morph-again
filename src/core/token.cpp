#include "token.h"

Token::Token(Token::Tag tag) :
        _tag(tag),
        _char(0)
{
    switch (_tag) {
        case OBRACE:
            _char = '{';
            break;
        case CBRACE:
            _char = '}';
            break;
        case OPAREN:
            _char = '(';
            break;
        case CPAREN:
            _char = ')';
            break;
        case COLON:
            _char = ':';
            break;
        case DQUOTE:
            _char = '"';
            break;
        case HCOLOR:
            _char = '#';
            break;
        default:
            _char = 0;
    }
}

Token::Token() :
_tag(INVALID),
_char(0) {

}

Token::Token(char c) :
    _tag(OTHER),
    _char(c)
{}

Token::~Token() {}

Tag Token::tag() const {
    return _tag;
}

char Token::operator*() const {
    return _char;
}

std::string Token::toString() const {
    return std::string(&_char, 1);
}
