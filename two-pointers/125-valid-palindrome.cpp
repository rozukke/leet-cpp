// Solution: use a pointer at each end to compare lowercase versions of each letter, skipping over non alpha-numeric
// characters.
// Requires O(n) time (half string length iterations) and O(1) memory (no size-dependent allocations required)
//
// Naive: reverse the string and go forwards through it

#include <string>
#include <cstdint>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (!std::isalnum(s[r])) {--r; continue;}
            if (!std::isalnum(s[l])) {++l; continue;}
            if (std::tolower(s[l]) != std::tolower(s[r])) return false;
            ++l;
            --r;
        }
        return true;
    }
};
