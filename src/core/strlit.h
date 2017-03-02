#ifndef STRLIT_H
#define STRLIT_H

#include <string>

#include "word.h"

class StrLit : public Word {
public:
    StrLit(const std::string &lit);

    int length() const;
private:
	int _length;
};

#endif // STRLIT_H
