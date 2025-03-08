// Solution: hashed datastructure like a set to store unique visited elements for O(1) lookups.
// Requires O(n) memory (at worst, all inputs are unique and require an entry) and O(n) memory
// (all inputs are visited every time).
// There is a non-transformation alternative where presence in the set is checked at each insertion
// to stop iteration early.
//
// Naive: for each entry, iterate through the list to find a duplicate for O(n^2) complexity.

#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set{nums.begin(), nums.end()};
        return nums.size() != set.size();
    }
};
