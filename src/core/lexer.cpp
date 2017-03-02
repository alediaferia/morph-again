//
// Created by Alessandro Diaferia on 25/01/2017.
//

#include "lexer.h"
#include "type.h"
#include "num.h"
#include "strlit.h"

Lexer::Lexer() :
    _peek(' '),
    _line(0)
{
    reserve(Word::And->toString(), Word::And);
    reserve(Word::Or->toString(), Word::Or);
    reserve(Word::Decl->toString(), Word::Decl);
    reserve(Word::Return->toString(), Word::Return);
    reserve(Word::True->toString(), Word::True);
    reserve(Word::False->toString(), Word::False);
    reserve(Type::Bool->toString(), Type::Bool);
    reserve(Type::Int->toString(), Type::Int);
    reserve(Type::Char->toString(), Type::Char);
}

void Lexer::reserve(const std::string &str, std::shared_ptr<Token> token) {
    _words[str] = token;
}

void Lexer::readNext() {
    _peek = *(_it++);
}

void Lexer::setSource(const std::string::const_iterator &it, const std::string::const_iterator &end) {
    _line = 0;
    _it = it;
    _end = end;
}

bool Lexer::expect(char c) {
    readNext();
    if (c != _peek)
        return false;

    _peek = ' ';
    return true;
}

std::shared_ptr<Token> Lexer::scan() {
    for (;; readNext()) {
        if (std::isspace(_peek))
            continue;
        else if (_peek == '\n')
            _line++;
        else
            break;
    }

    // TODO
    // parse color hashes #1122ee

    switch (_peek) {
        case '&':
            if (expect('&'))
                return Word::And;
            else
                return std::make_shared<Token>('&');
        case '|':
            if (expect('|'))
                return Word::Or;
            else
                return std::make_shared<Token>('|');
        case '=':
            if (expect('='))
                return Word::Eq;
            else
                return std::make_shared<Token>('=');
        case '<':
            if (expect('='))
                return Word::Le;
            else
                return std::make_shared<Token>('<');
        case '>':
            if (expect('='))
                return Word::Ge;
            else
                return std::make_shared<Token>('>');
        case '!':
            if (expect('='))
                return Word::Ne;
            else
                return std::make_shared<Token>('!');
    }

    if (std::isdigit(_peek)) {
        std::string num_s;
        do {
            num_s += _peek;
            readNext();
        } while (std::isdigit(_peek));

        if (_peek != '.')
            return std::make_shared<Num>(std::stoi(num_s, nullptr, 10));

        // TODO
        // implement Real support
    }

    if (std::isalpha(_peek)) {
        std::string buf;
        do {
            buf += _peek;
            readNext();
        } while(std::isalnum(_peek));

        auto reserved = _words[buf];
        if (!reserved) {
            reserved = std::make_shared<Word>(buf, Token::ID);
            _words[buf] = reserved;
        }

        return reserved;
    }

    if (_peek == '"') {
        readNext();
        std::string buf;
        do {
            buf += _peek;
            readNext();
        } while(_peek != '"');
        _peek = ' ';
        return std::make_shared<StrLit>(buf);
    }

    auto t = std::make_shared<Token>(_peek);
    _peek = ' ';
    return t;
}
