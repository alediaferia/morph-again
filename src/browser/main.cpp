#include "parser.h"
#include "attribute.h"
#include "parser.h"

#include <iostream>

int main(int argc, char *argv[]) {
    Parser parser;
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        auto it = input.cbegin();
        auto end = input.cend();

        parser.reset(it, end);

        Token tok = parser.nextToken();
        if (tok.type == Token::IDENT) {
            if (tok.value == "var") {
                parser.parseVariableDecl();
                std::cout << "var decl;" << std::endl;
                continue;
            }

            std::cout << "node: " << tok.value << std::endl;
            if (parser.nextToken().type == Token::BRACE_OPEN) {
                auto attributes = parser.parseAttributes();
                std::cout << "attrs:{ " << std::endl;
                for (auto attr : attributes) {
                    std::cout << "- " << attr->toString() << std::endl;
                }
                std::cout << " }" << std::endl;
            }
        }
    }

    return 0;
}
