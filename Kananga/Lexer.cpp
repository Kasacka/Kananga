#include "Lexer.hpp"

bool Lexer::hasNextToken() {
    readWhile(isspace);
    return charIndex < source.size();
}

Token Lexer::nextToken() {
    if (!hasNextToken()) {
        return Token{charIndex, "", TokenType::EndOfProgram};
    }
    
    int startIndex{charIndex};
    std::string tokenValue{};
    TokenType type{};
    
    if (isalpha(source[charIndex])) {
        tokenValue = readWhile(isalpha);
        
        if (tokenValue == "class") {
            type = TokenType::Class;
        } else if (tokenValue == "end") {
            type = TokenType::End;
        } else {
            type = TokenType::Identifier;
        }
    }
    
    return Token{startIndex, tokenValue, type};
}

std::string Lexer::readWhile(std::function<bool(char)> predicate) {
    int startIndex{charIndex};
    
    while (charIndex < source.size() && predicate(source[charIndex])) {
        ++charIndex;
    }
    
    return source.substr(startIndex, charIndex - startIndex);
}
