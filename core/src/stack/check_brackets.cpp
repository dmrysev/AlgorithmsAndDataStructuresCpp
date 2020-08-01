#include "stack/check_brackets.hpp"
#include "util/collection.h"

#include <stack>

namespace AlgorithmsAndDataStructures::Core::Stack::CheckBrackets {

using namespace Util::Collection;

namespace  {

bool isClosingBracket(char bracket1, char bracket2) {
    if(bracket1 == '{' && bracket2 == '}') return true;
    else if(bracket1 == '[' && bracket2 == ']') return true;
    else if(bracket1 == '(' && bracket2 == ')') return true;
    return false;
}

bool isLeftBracket(char bracket) {
    return contains("{[(", bracket);
}

}

bool checkBrackets(std::string brackets) {
    std::stack<char> bracketsStack;
    for(char bracket: brackets) {
        if(isLeftBracket(bracket)) {
            bracketsStack.push(bracket);
        }
        else if(!bracketsStack.empty() && isClosingBracket(bracketsStack.top(), bracket)) {
            bracketsStack.pop();
        }
        else return false;
    }
    return bracketsStack.empty();
}

}
