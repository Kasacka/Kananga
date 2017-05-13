#ifndef Token_hpp
#define Token_hpp

#include "TokenType.hpp"
#include <string>

class Token {
    int position{};
    std::string value{};
    TokenType type{};
    
public:
    Token(int position, std::string value, TokenType type)
        : position{position}, value{value}, type{type} {
    }
    
    int getPosition() const;
    std::string getValue() const;
    TokenType getType() const;
};

#endif
