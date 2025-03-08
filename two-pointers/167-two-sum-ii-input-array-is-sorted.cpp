// Solution: from both ends, move up pointers until the target is found. If the current sum is less
// than the target, incrementing l increases the sum. If the current sum is more than the target,
// incrementing decreases the sum.
// Requires O(1) memory and O(n) time complexity (iterated once).
//
// Naive: O(n^2) solution of iterating through the input for each number, or O(n log n) solution
// to binary search for the complement of each number.

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        // can be uint16_t
        int l = 0;
        int r = numbers.size() - 1;

        // can be while true
        while (l < r) {
            if (numbers[l] + numbers[r] == target) return {l + 1, r + 1};

            if ((numbers[l] + numbers[r]) > target) {
                --r;
            } else {
                ++l;
            }
        }

        // unreachable
        return {};
    }
};
