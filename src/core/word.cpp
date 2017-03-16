//
// Created by Alessandro Diaferia on 25/01/2017.
//

#include "word.h"

std::shared_ptr<Word> Word::And(new Word("&&", Token::AND));
std::shared_ptr<Word> Word::Or(new Word("||", Token::OR));
std::shared_ptr<Word> Word::Decl(new Word("decl", Token::DECL));
std::shared_ptr<Word> Word::Return(new Word("return", Token::RETURN));
std::shared_ptr<Word> Word::True(new Word("true", Token::TRUE));
std::shared_ptr<Word> Word::False(new Word("false", Token::FALSE));
std::shared_ptr<Word> Word::Eq(new Word("eq", Token::EQ));
std::shared_ptr<Word> Word::Ge(new Word("ge", Token::GE));
std::shared_ptr<Word> Word::Le(new Word("le", Token::LE));
std::shared_ptr<Word> Word::Ne(new Word("ne", Token::NE));
std::shared_ptr<Word> Word::Fn(new Word("fn", Token::FN));

Word::Word(const std::string &s, Token::Tag tag) : Token(tag),
_lexeme(s) {

}

std::string Word::toString() const {
    return _lexeme;
}
