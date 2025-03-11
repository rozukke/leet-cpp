#include <vector>
#include <cstdint>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, uint64_t h) {
        std::sort(piles.begin(), piles.end());

        int upper_bound = piles[piles.size() - 1];
        int lower_bound = 1;

        // Iterate down from max value
        while (lower_bound < upper_bound) {
            uint64_t total_hours = 0;
            uint64_t eating_speed = lower_bound + (upper_bound - lower_bound) / 2;

            for (uint64_t pile : piles) {
                // ceiling division
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
