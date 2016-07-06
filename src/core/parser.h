#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <memory>

class Attribute;

class Parser {
public:
    typedef std::string::const_iterator StrIterator;
    enum Token {
        TOK_IDENT,
        TOK_ATTR_OPEN,
        TOK_ATTR_CLOSE,
        TOK_ATTR_SEP,
        TOK_INDENT,
        TOK_NUM, // number (int)
        TOK_LIT, // literal
	TOK_COMMA,
        TOK_EOL,
        TOK_UNKNOWN
    };
    Parser();

    std::string lastIdentifier() const;
    std::string lastLiteral() const;

    Token nextToken(StrIterator &it,
                    StrIterator &end);
    std::unique_ptr<Attribute> parseAttribute(StrIterator &it,
		    			      StrIterator &end);
protected:

private:
    std::string _currentIdentifier;
    std::string _currentLiteral;
    int _currentNum;
    int _lastChar;
};

#endif // PARSER_H
