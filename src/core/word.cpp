//
// Created by Alessandro Diaferia on 25/01/2017.
//

#include "word.h"

static std::shared_ptr<Word> Word::And(new Word("&&", Token::AND));
static std::shared_ptr<Word> Word::Or(new Word("||", Token::OR));
static std::shared_ptr<Word> Word::Decl(new Word("decl", Token::DECL));
static std::shared_ptr<Word> Word::Return(new Word("return", Token::RETURN));
static std::shared_ptr<Word> Word::True(new Word("true", Token::TRUE));
static std::shared_ptr<Word> Word::False(new Word("false", Token::FALSE));
static std::shared_ptr<Word> Word::Int(new Word("int", Token::ID));
static std::shared_ptr<Word> Word::Bool(new Word("bool", Token::ID));
static std::shared_ptr<Word> Word::Eq(new Word("eq", Token::EQ));
static std::shared_ptr<Word> Word::Ge(new Word("ge", Token::GE));
static std::shared_ptr<Word> Word::Le(new Word("le", Token::LE));
static std::shared_ptr<Word> Word::Ne(new Word("ne", Token::NE));

Word::Word(const std::string &s, Token::Tag tag) : Token(tag),
_lexeme(s) {

}

std::string Word::toString() const {
    return _lexeme;
}
