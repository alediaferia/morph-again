#include "parser.h"

#include <iostream>

Parser::Parser() :
_lastChar(' '),
_currentNum(0)
    {}

Parser::Token Parser::nextToken(std::string::const_iterator &it,
                                std::string::const_iterator &end) {
    while (it != end && isspace(_lastChar))
        _lastChar = *(it++);

    if (isalpha(_lastChar)) { // checking for identifier
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
        if (it != end)
            _lastChar = *(it++);
        else
            _lastChar = ' ';
        return TOK_ATTR_OPEN;
    }

    if (_lastChar == '}') {
        if (it != end)
            _lastChar = *(it++);
        else
            _lastChar = ' ';
        return TOK_ATTR_CLOSE;
    }

    if (_lastChar == ':') {
        if (it != end)
            _lastChar = *(it++);
        else
            _lastChar = ' ';
        return TOK_ATTR_SEP;
    }
    
    if (_lastChar == '"') {
        _currentLiteral.clear();
        if (it != end)
            _lastChar = *(it++);
        do {
            if (_lastChar == '"')
                return TOK_LIT;
            _currentLiteral += _lastChar;
            _lastChar = *(it++);
        } while (it != end);

    }
    
    if (it == end) {
        return TOK_EOL;
    }

    return TOK_UNKNOWN;
}

std::string Parser::lastIdentifier() const {
    return _currentIdentifier;
}

std::string Parser::lastLiteral() const {
    return _currentLiteral;
}
