#include "Parser.hpp"
#include <iostream>

int main() {
    Parser parser{"class Fish end class Animal      end class Bird end"};
    
    parser.parse();
}
