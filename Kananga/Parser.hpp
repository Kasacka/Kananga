#ifndef Parser_hpp
#define Parser_hpp

#include "Lexer.hpp"
#include "Token.hpp"
#include "TokenType.hpp"
#include "ProgramNode.hpp"
#include <string>

class Parser {
    Lexer lexer;
    Token currentToken;
    
    void expect(TokenType type);
    bool is(TokenType type);
    std::string readIdentifier();
    
public:
    Parser(std::string source)
        : lexer{source}, currentToken{lexer.nextToken()} {
    }
    
    ProgramNode parse();
};

#endif
