#include <vector>
#include <iostream>

class Solution {
public:
    int trap(const std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int total = 0;

        // Edges cannot contain rainwater
        while (l < r && height[l] == 0) ++l;
        while (l < r && height[r] == 0) --r;

        int water_level = std::min(height[l], height[r]);
        while (l < r) {
            int current;
            // only calculate new bigger size after the current one is exceeded
            if (height[l] < height[r]) {
                water_level = std::max(height[l], water_level);
                current = ++l;
            } else {
                water_level = std::max(height[r], water_level);
                current = --r;
            }

            // update total
            int diff = water_level - height[current];
            if (diff > 0) total += diff;
        }
        return total;
    }
};

int main() {
    Solution a;
    std::cout << a.trap({4, 2, 0, 3, 2, 5}) << std::endl;
}
