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
            } else if (tok == Parser::TOK_ATTR_OPEN) {
                std::unique_ptr<Attribute> attr = parser.parseAttribute(it, end);
                if (!attr) {
                    std::cout << "Error: unable to parse attribute" << std::endl;
                    continue;
                }
                std::cout << "Parsed attribute: (name: " << attr->name() << ", value: " << attr->value() << ")" << std::endl;
            } else if (tok == Parser::TOK_ATTR_CLOSE) {
                std::cout << "attr end;" << std::endl;
            } else if (tok == Parser::TOK_LIT) {
                std::cout << "Literal: \"" << parser.lastLiteral() << "\"" << std::endl;
            } else if (tok == Parser::TOK_EOL) {
                break;
            }
        } while (true);
    }

    return 0;
}
