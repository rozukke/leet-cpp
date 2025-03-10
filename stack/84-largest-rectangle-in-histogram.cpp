#include <vector>

using pair_t = std::pair<int, int>;

class Solution {
public:
    int largestRectangleAreaSlow(std::vector<int>& heights) {
        std::vector<pair_t> stack;
        int max_height = 0;

        for (const auto curr_height : heights) {
            if (stack.empty()) {
                stack.emplace_back(curr_height, 1);
                continue;
            }

            auto [value, length] = stack.back();
            if (curr_height == value) {
                ++stack.back().second;
            } else if (curr_height > value) {
                // increase len
                stack.emplace_back(height, 1);
            } else {
                int last_length = 0;
                // Remove any bigger heights off the stack as they have now ended
                // Make sure to update max value to preserve the info
                while (!stack.empty() && stack.back().first > curr_height) {
                    auto [value, length] = stack.back();
                    curr_length += length;
                    // Update max_height
                    max_height = std::max(max_height, value * length);
                    stack.pop_back();
                }
                stack.emplace_back(height, curr_length + 1);
            }

        }
    }

    int largestRectangleAreaSlow(vector<int>& heights) {
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int area = 0;
            int j = i;
            while (j < heights.size() && heights[j] >= heights[i]) {
                area += heights[j];
                ++j;
            }
            j = i - 1;
            while (j >= 0 && heighs[j] >= heights[i]) {
                area += heights[j];
                --j;
            }
            max_area = std::max(area, max_area);
        }
        return max_area;
    }
};
