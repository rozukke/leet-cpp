// Solution: recursion to traverse all permutations.
// NOTE: Lesson learnt. Do not fuck with recursion. Base case at the top, everything else below.

#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        // for each one, first do open bracket, then do closed bracket
        std::string stack = "(";
        std::vector<std::string> results;
        results.reserve(factorial(n) / 2);
        stack.reserve(n);

        int open = 1;
        traverse(n, stack, 1, 0, results);
        return results;
    }

    void traverse(int max_len, std::string stack, int open, int closed, std::vector<std::string>& results) {
        if (stack.size() == max_len * 2) {
            results.push_back(stack);
            return;
        }

        if (open < max_len) {
            stack.push_back('(');
            traverse(max_len, stack, open + 1, closed, results);
            stack.pop_back();
        }
        if (closed < open) {
            stack.push_back(')');
            traverse(max_len, stack, open, closed + 1, results);
            stack.pop_back();
        }
    }

    int factorial(int n) {
        for (int i = n - 1; i > 0; --i) {
            n *= i;
        }
        return n;
    }
};
