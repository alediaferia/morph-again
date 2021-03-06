//
// Created by Alessandro Diaferia on 25/01/2017.
//

#ifndef LEXER_H
#define LEXER_H

#include <map>
#include "token.h"
#include "word.h"

class Lexer {
public:
    Lexer();

    void setSource(const std::string::const_iterator &it,
                    const std::string::const_iterator &end);

    std::shared_ptr<Token> scan();

    void reserve(const std::string &str, std::shared_ptr<Token> token);

    bool eof() const;

protected:
    void readNext();
    bool expect(char c);

private:
    char _peek;
    std::string::const_iterator _it;
    std::string::const_iterator _end;
    int _line;
    std::map<std::string, std::shared_ptr<Token>> _words;
};


#endif // LEXER_H
