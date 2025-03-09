#include <vector>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> in_stack;
        in_stack.reserve(tokens.size());

        for (const auto& token : tokens) {
            // Numeric token
            if (std::isdigit(token[0]) || (token[0] == '-' && token.size() != 1)) {
                int parsed = std::stoi(token);
                in_stack.push_back(parsed);
            } else {
                int right = in_stack.back();
                in_stack.pop_back();
                int left = in_stack.back();
                in_stack.pop_back();

                switch (token[0]) {
                    case '/':
                        in_stack.push_back(left / right);
                        break;
                    case '-':
                        in_stack.push_back(left - right);
                        break;
                    case '*':
                        in_stack.push_back(left * right);
                        break;
                    case '+':
                        in_stack.push_back(left + right);
                        break;
                }
            }
        }

        return in_stack.back();
    }
};
