#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set{nums.begin(), nums.end()};
        return nums.size() != set.size();
    }
};
