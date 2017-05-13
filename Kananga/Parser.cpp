#include "Parser.hpp"
#include <iostream>

void Parser::expect(TokenType type) {
    if (is(type)) {
        currentToken = lexer.nextToken();
    } else {
        throw 1;
    }
}

std::string Parser::readIdentifier() {
    if (is(TokenType::Identifier)) {
        auto value = currentToken.getValue();
        currentToken = lexer.nextToken();
        return value;
    } else {
        throw 2;
    }
}

bool Parser::is(TokenType type) {
    return currentToken.getType() == type;
}

ProgramNode Parser::parse() {
    while (is(TokenType::Class)) {
        expect(TokenType::Class);
        auto className = readIdentifier();
        expect(TokenType::End);
        std::cout << "CLASS " << className << " parsed...\n";
    }
    
    expect(TokenType::EndOfProgram);
    
    return ProgramNode{};
}
