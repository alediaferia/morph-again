#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser {
public:
    enum Token {
        TOK_IDENT,
        TOK_ATTR_OPEN,
        TOK_ATTR_CLOSE,
        TOK_ATTR_SEP,
        TOK_INDENT,
        TOK_NUM, // number (int)
        TOK_LIT, // literal
        TOK_EOL,
        TOK_UNKNOWN
    };
    Parser();

    std::string lastIdentifier() const;

    Token nextToken(std::string::const_iterator &it,
                    std::string::const_iterator &end);
protected:

private:
    std::string _currentIdentifier;
    std::string _currentLiteral;
    int _currentNum;
    int _lastChar;
};

#endif // PARSER_H
