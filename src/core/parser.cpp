#include "parser.h"

#include <iostream>

Parser::Parser() {}

Parser::Token Parser::nextToken(std::string::const_iterator it,
                                std::string::const_iterator end) {
    int lastChar = ' ';
    while (it != end && isspace(lastChar))
        lastChar = *(it++);

    if (isalpha(lastChar)) { // might be an identifier
        _currentIdentifier.clear();
        _currentIdentifier += lastChar;
        lastChar = *(it++);
        while (isalnum(lastChar) && it != end) {
            _currentIdentifier += lastChar;
            lastChar = *(it++);
        }

        return TOK_IDENT;
    }

    return TOK_UNKNOWN;
}

std::string Parser::lastIdentifier() const {
    return _currentIdentifier;
}
