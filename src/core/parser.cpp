#include "parser.h"

#include <iostream>

Parser::Parser() :
_lastChar(' ')
    {}

Parser::Token Parser::nextToken(std::string::const_iterator &it,
                                std::string::const_iterator &end) {
    while (it != end && isspace(_lastChar))
        _lastChar = *(it++);

    if (isalpha(_lastChar)) { // might be an identifier
        _currentIdentifier.clear();
        _currentIdentifier += _lastChar;
        _lastChar = *(it++);
        while (isalnum(_lastChar) || _lastChar == '-') {
            _currentIdentifier += _lastChar;
            if (it == end)
                break;
            _lastChar = *(it++);
        }

        return TOK_IDENT;
    }

    if (_lastChar == '{') {
        _lastChar = *(it++);
        return TOK_ATTR_OPEN;
    }

    if (_lastChar == '}') {
        _lastChar = *(it++);
        return TOK_ATTR_CLOSE;
    }

    if (_lastChar == ':') {
        _lastChar = *(it++);
        return TOK_ATTR_SEP;
    }

    return TOK_UNKNOWN;
}

std::string Parser::lastIdentifier() const {
    return _currentIdentifier;
}
