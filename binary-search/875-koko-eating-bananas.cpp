// Solution: time complexity of O(n log m) where m is the size of the maximum value.
// (for each iteration of a binary search with an upper bound of max value, iterate
// input array once). Space complexity of O(1).
// Naive solution is same but without binary search.

#include <vector>
#include <cstdint>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, uint64_t h) {
        int upper_bound = *std::max_element(piles.begin(), piles.end());
        int lower_bound = 1;

        // Search value of k bounded by the maximum element in piles
        while (lower_bound < upper_bound) {
            uint64_t total_hours = 0;
            uint64_t eating_speed = lower_bound + (upper_bound - lower_bound) / 2;

            for (uint64_t pile : piles) {
                // Ceiling division
                total_hours += pile / eating_speed + (pile % eating_speed != 0);
            }

            if (total_hours <= h) {
                upper_bound = eating_speed;
            } else {
                lower_bound = eating_speed + 1;
            }

        }
        return upper_bound;
    }
};
