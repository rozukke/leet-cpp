#include <vector>

using pair_t = std::pair<int, int>;

class Solution {
public:
    int largestRectangleArea(const std::vector<int>& heights) {
        std::vector<pair_t> stack;
        int max_area = 0;

        for (int i = 0; i <= heights.size(); ++i) {
            // Need a way to run the stack popping at the end without awkward code duplication
            int curr_height = i == heights.size() ? 0 : heights[i];

            if (stack.empty()) {
                stack.emplace_back(curr_height, 1);
                continue;
            }

            int last_height = stack.back().first;
            if (curr_height == last_height) {
                // Same height, add one extra length
                ++stack.back().second;
            } else if (curr_height > last_height) {
                // Larger, creates new possible largest rectangle
                stack.emplace_back(curr_height, 1);
            } else {
                int total_length = 0;
                // Remove any bigger heights off the stack as they have now ended
                // Make sure to update max value to preserve the info
                while (!stack.empty() && stack.back().first >= curr_height) {
                    auto [curr_height, curr_length] = stack.back();
                    total_length += curr_length;
                    // Update max_height
                    max_area = std::max(max_area, curr_height * total_length);
                    stack.pop_back();
                }
                stack.emplace_back(curr_height, total_length + 1);
            }
        }

        return max_area;
    }

    // TLE on leetcode
    int largestRectangleAreaSlow(std::vector<int>& heights) {
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int area = 0;
            int j = i;
            while (j < heights.size() && heights[j] >= heights[i]) {
                area += heights[j];
                ++j;
            }
            j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) {
                area += heights[j];
                --j;
            }
            max_area = std::max(area, max_area);
        }
        return max_area;
    }
};

int main() {
    Solution a;
    a.largestRectangleArea(std::vector{2, 1, 5, 6, 2, 3});
}
