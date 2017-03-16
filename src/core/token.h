#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
public:
    enum Tag {
        INVALID = -1000,
        OTHER = -1,
        ID = 1,
        OBRACE,
        CBRACE,
        OPAREN,
        CPAREN,
        COLON,
        NUM,
        DQUOTE,
        TRUE,
        FALSE,
        HCOLOR, // for having color hashes (#aaB0f1) as a language type,
        DECL,
        AND,
        OR,
        RETURN,
        EQ,
        GE,
        LE,
        NE,
        BASIC,
        INDEX,
        VAR,
        STRLIT,
        FN
    };

    Token();
    Token(Tag tag);
    Token(char c);
    virtual ~Token();

    Tag tag() const;
    char operator *() const;

    virtual std::string toString() const;

private:
    Tag _tag;
    char _char;
};

#endif
