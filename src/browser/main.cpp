#include "parser.h"
#include "attribute.h"

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

                auto attributes = parser.parseAttributes(it, end);
                std::cout << "attrs:{ " << std::endl;
                for (auto attr : attributes) {
                    std::cout << attr->toString() << std::endl;
                }
                std::cout << " }" << std::endl;
                
            } else if (tok == Parser::TOK_LIT) {
                std::cout << "Literal: \"" << parser.lastLiteral() << "\"" << std::endl;
            } else if (tok == Parser::TOK_EOL) {
                break;
            }
        } while (true);
    }

    return 0;
}
