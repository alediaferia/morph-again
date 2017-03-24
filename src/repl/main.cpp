#include "core/attribute.h"
#include "core/parser.h"
#include "core/token.h"
#include "core/lexer.h"

#include <iostream>
#include <string>
#include <memory>

int main(int argc, char *argv[]) {
    auto lexer = std::unique_ptr<Lexer>(new Lexer());
    Parser parser(std::move(lexer));
    while (true) {
        std::string input;

        std::cout << "sand#> ";
        std::getline(std::cin, input);
        parser.setInput(input);

        auto node = parser.program(false);
        std::cout << std::endl << "~> " << node->toString() << std::endl;
        std::cout << "Code Generation:" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << node->toValue()->toString() << std::endl;
    }

    return 0;
}
