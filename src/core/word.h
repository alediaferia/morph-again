//
// Created by Alessandro Diaferia on 25/01/2017.
//

#ifndef WORD_H
#define WORD_H

#include "token.h"

#include <memory>

class Word : public Token {
public:
    Word(const std::string &s, Token::Tag);

    static std::shared_ptr<Word> And;
    static std::shared_ptr<Word> Or;
    static std::shared_ptr<Word> Decl;
    static std::shared_ptr<Word> Return;
    static std::shared_ptr<Word> True;
    static std::shared_ptr<Word> False;
    static std::shared_ptr<Word> Eq;
    static std::shared_ptr<Word> Ge;
    static std::shared_ptr<Word> Le;
    static std::shared_ptr<Word> Ne;

    virtual std::string toString() const override;

private:
    std::string _lexeme;
};


#endif //MORPH_AGAIN_WORD_H
