#include "parser.h"

#include <iostream>

int main(int argc, char *argv[]) {

    std::string input;
    Parser parser;
    while (true) {
        std::cin >> input;
        auto it = input.cbegin();
        auto end = input.cend();

        do {
            Parser::Token tok = parser.nextToken(it, end);
            if (tok == Parser::TOK_IDENT) {
                std::cout << "node: " << parser.lastIdentifier() << std::endl;
            } else if (tok == Parser::TOK_ATTR_OPEN) {
                std::cout << "attr begin;" << std::endl;
            } else if (tok == Parser::TOK_ATTR_CLOSE) {
                std::cout << "attr end;" << std::endl;
            }
        } while (it != end);
    }

    return 0;
}
