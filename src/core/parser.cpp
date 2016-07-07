#include "parser.h"
#include "attribute.h"

#include <iostream>

Parser::Parser() :
_lastChar(' '),
_currentNum(0)
    {}

Parser::Token Parser::nextToken(std::string::const_iterator &it,
                                std::string::const_iterator &end) {
    while (it != end && isspace(_lastChar))
        _lastChar = *(it++);

    if (std::isalpha(_lastChar)) { // checking for identifier
        _currentIdentifier.clear();
        _currentIdentifier += _lastChar;
        _lastChar = *(it++);
        while (std::isalnum(_lastChar) || _lastChar == '-') {
            _currentIdentifier += _lastChar;
            if (it == end)
                break;
            _lastChar = *(it++);
        }
        return TOK_IDENT;
    }

    if (isdigit(_lastChar)) { // number [0-9]
        std::string num;
        do {
          num += _lastChar;
        } while (it != end && isdigit((_lastChar = *(it++))));
        _currentNum = strtol(num.c_str(), nullptr, 10);

        return TOK_NUM;
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

    if (_lastChar == ',') {
        if (it != end)
            _lastChar = *(it++);
        else
            _lastChar = ' ';
        return TOK_COMMA;
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

std::shared_ptr<Attribute> Parser::parseAttribute(StrIterator &it, StrIterator &end) {
    Token tok = nextToken(it, end);
    if (tok != TOK_IDENT) {
        std::cerr << "Syntax: got " << tok << " but expected identifier" << std::endl;
        return std::shared_ptr<Attribute>();
    }

    std::string name(_currentIdentifier);
    
    tok = nextToken(it, end);
    if (tok != TOK_ATTR_SEP) {
        std::cerr << "Syntax: got " << tok << " but expected :" << std::endl;
        return std::shared_ptr<Attribute>();
    }

    tok = nextToken(it, end);
    if (tok != TOK_NUM) {
	    std::cerr << "Syntax: got " << tok << " but expected a number" << std::endl;
	    return std::shared_ptr<Attribute>();
    }

    return std::shared_ptr<Attribute>(new Attribute(name, _currentNum));
}

std::set<std::shared_ptr<Attribute>> Parser::parseAttributes(StrIterator &it, StrIterator &end) {
    Token tok = nextToken(it, end);
    if (tok != TOK_ATTR_OPEN) {
        std::cerr << "Syntax: got " << tok << " but expected {" << std::endl;
        return decltype(Parser::parseAttributes(it, end))();
    }    
    auto attributes = decltype(Parser::parseAttributes(it, end))();

    while (true) {
        tok = nextToken(it, end);
        if (tok == TOK_EOL) {
            std::cerr << "Syntax: unexpected end of input: expected }" << std::endl;
            return decltype(Parser::parseAttributes(it, end))();
        } else if (tok == TOK_ATTR_CLOSE) {
            return attributes;
        } else if (tok == TOK_COMMA) {
            auto attr = parseAttribute(it, end);
            if (!attr) {
                return decltype(Parser::parseAttributes(it, end))();
            }
            attributes.insert(attr);
            continue;
        }
    }

    return attributes;
}

