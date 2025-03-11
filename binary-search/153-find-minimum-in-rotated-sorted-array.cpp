// Solution: first try! O(log n) since 2 binary searches are required on half of each array.
// Finding the local minimum of each half and comparing them is enough to determine where
// the overall minimum is.
// The trick is to set the comparison to the rightmost value to capture the minimum in all
// cases.
//
// NOTE: This property holds for the array itself... so as long as the rightmost value is
// used for the comparison, the minimum is guaranteed to be found. Therefore, 2 searches
// are not needed.

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int middle = nums.size() / 2;
        // Binary search bottom half
        int bottom_min = binarySearchMin(0, middle, nums);
        if (bottom_min > 0) return nums[bottom_min];
        // Binary search top half
        int top_min = binarySearchMin(middle, nums.size() - 1, nums);
        // Middle checked already
        if (top_min != middle) {
            return nums[top_min];
        } else {
            return nums[0];
        }
    }

    // Returns index
    inline int binarySearchMin(int l, int r, std::vector<int>& nums) {
        // Makes sure that the minimum is guaranteed to be checked
        int current = nums[r];

        while (l < r) {
            int search_index = l + (r - l) / 2;

            if (nums[search_index] <= current) {
                r = search_index;
            } else {
                l = search_index + 1;
            }
        }

        return r;
    }
};

// 5, 6, 7, 8, 1, 2, 3, 4
