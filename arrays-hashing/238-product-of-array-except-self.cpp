// Solution: keep track of the product on both sides of each value by precalculating all the products in one direction.
// This can be improved by reusing the space dedicated for the output for O(1) memory requirement (since no extra
// allocations are made that are dependent on input size). Time complexity is O(n) (one run-through for each direction).
//
// Naive: for each value, iterate forwards up to the value, keeping a product, and iterate backwards up to the value,
// keeping the product. This would result in a time complexity of O(n^2) (one iteration of the input per item) and a
// space complexity of O(1) (since no allocations need to be made).

#include <vector>
#include <memory>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int size = nums.size();

        std::vector<int> result;
        result.reserve(size);

        auto suffixes = std::vector<int>;
        suffixes.reserve(size + 1);
        // Account for last value
        suffixes[size] = 1;

        // Init first value
        suffixes[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            suffixes[i] = suffixes[i + 1] * nums[i];
        }

        // Push first value (not idx to preserve uninit memory)
        result.push_back(suffixes[1]);

        // Init first value
        int prefix = nums[0];
        for (int i = 1; i < size; ++i) {
            result.push_back(prefix * suffixes[i + 1]);
            prefix *= nums[i];
        }

        return result;
    }

    std::vector<int> productExceptSelfDP(const std::vector<int>& nums) {
        int size = nums.size();

        std::vector<int> result;
        result.resize(size);

        result[size - 1] = nums[size - 1];
        for (int i = size - 2; i > 0; --i) {
            result[i] = nums[i] * result[i + 1];
        }

        // Account for first value
        result[0] = result[1];
        int prefix = nums[0];
        for (int i = 1; i < size - 1; ++i) {
            result[i] = prefix * result[i + 1];
            prefix *= nums[i];
        }
        result[size - 1] = prefix;

        return result;
    }
};
