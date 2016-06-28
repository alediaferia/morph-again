#include "parser.h"

#include <iostream>

int main(int argc, char *argv[]) {

    std::string input;
    Parser parser;
    while (true) {
        std::cin >> input;
        Parser::Token tok = parser.nextToken(input.cbegin(), input.cend());
        if (tok == Parser::TOK_IDENT) {
            std::cout << "id: " << parser.lastIdentifier() << std::endl;
        }
    }

    return 0;
}
