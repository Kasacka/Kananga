#include "Token.hpp"

int Token::getPosition() const {
    return position;
}

std::string Token::getValue() const {
    return value;
}

TokenType Token::getType() const {
    return type;
}
