// Solution: to make sure that all relevant options are explored, we use two pointers to
// keep track of the current area. Whichever pointer has a smaller value is incremented
// towards the middle, to make sure that all areas of increasing size are explored.
// Requires O(n) time (all heights iterated) and O(1) space (no n dependent alloations made).

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int result = 0;
        while (l < r) {
            result = std::max(result, (r - l) * std::min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};
