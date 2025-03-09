#include <stack>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::vector<char> stack;
        // On average, half the brackets will be opening and go on stack
        stack.reserve(s.size() / 2);

        for (char c : s) {
            switch (c) {
                case '(':
                    stack.push_back(')');
                    break;
                case '{':
                    stack.push_back('}');
                    break;
                case '[':
                    stack.push_back(']');
                    break;
                case ')':
                case ']':
                case '}':
                    if (stack.size() == 0) return false;

                    char popped = *stack.end();
                    stack.pop_back();
                    if (popped != c) return false;
            }
        }
        if (stack.size() == 0) return true;
        return false;
    }
};
