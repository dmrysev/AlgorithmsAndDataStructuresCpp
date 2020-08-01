#include "stack/check_brackets.hpp"
#include "util/collection.h"

#include <stack>

namespace AlgorithmsAndDataStructures::Stack::CheckBrackets {

using namespace Util::Collection;

bool isClosingBracket(char bracket1, char bracket2) {
    if(bracket1 == '{' && bracket2 == '}') return true;
    else if(bracket1 == '[' && bracket2 == ']') return true;
    else if(bracket1 == '(' && bracket2 == ')') return true;
    return false;
}

bool checkBrackets(std::string brackets) {
    std::stack<char> bracketsStack;
    for(char bracket: brackets) {
        if(!bracketsStack.empty() && isClosingBracket(bracketsStack.top(), bracket)) {
            bracketsStack.pop();
        }
        else {
            bracketsStack.push(bracket);
        }
    }
    return bracketsStack.empty();
}

}
