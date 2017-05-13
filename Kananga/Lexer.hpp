#ifndef Lexer_hpp
#define Lexer_hpp

#include "Token.hpp"
#include <string>
#include <functional>

class Lexer {
    std::string source{};
    int charIndex{};
    
    std::string readWhile(std::function<bool(char)> predicate);
    
public:
    Lexer(std::string source)
        : source{source} {
    }
    
    bool hasNextToken();
    Token nextToken();
};

#endif
