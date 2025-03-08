// Solution: store the location of the complement of each number that would be required to reach
// the target in a hashmap for O(1) lookups. If the complement exists in the map, return the indexes of both.
// Requires at most O(n) memory (one map entry for each input) and O(n) time complexity (each input is visited once).
//
// Naive: for every number, iterate the input list to look for a suitable complement.
// Requires O(1) memory and O(n^2) time complexity (the whole array visited per input).

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map{};
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (map.find(num) != map.end()) {
                return {map[num], i};
            }
            map[target - num] = i;
        }
        // unreachable
        return {0, 0};
    }
};
