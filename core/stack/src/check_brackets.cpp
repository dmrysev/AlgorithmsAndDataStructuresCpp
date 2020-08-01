#include "stack/check_brackets.hpp"
#include "util/collection.h"

#include <stack>

namespace AlgorithmsAndDataStructures::Stack::CheckBrackets {

using namespace Util::Collection;

bool isClosingsBrackets(char openingBracket, char closingBracket2) {
    if(openingBracket == '{' && closingBracket2 == '}') return true;
    else if(openingBracket == '[' && closingBracket2 == ']') return true;
    else if(openingBracket == '(' && closingBracket2 == ')') return true;
    return false;
}

bool checkBrackets(std::string brackets) {
    std::stack<char> bracketsStack;
    for(char bracket: brackets) {
        if(!bracketsStack.empty() && isClosingsBrackets(bracketsStack.top(), bracket)) {
            bracketsStack.pop();
        }
        else {
            bracketsStack.push(bracket);
        }
    }
    return bracketsStack.empty();
}

}
