// Solution: use a set to collect all unique elements, then iterate through to find the longest sequence.
// Time complexity O(n log n) due to insertion into set, and O(n) memory (set contains one entry per element).
//
// NOTE: This one is very weird and times out/performs badly on leetcode

#include <set>
#include <unordered_map>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::set<int> set;
        for (const auto num : nums) {
            set.insert(num);
        }

        uint32_t max_seq = 0;
        uint32_t curr_seq = 0;
        int curr_num = 0;
        for (const auto num : set) {
            if (num != curr_num + 1) {
                curr_seq = 0;
            }
            curr_num = num;
            curr_seq += 1;
            max_seq = curr_seq > max_seq ? curr_seq : max_seq;
        }
        return max_seq;
    }

    int longestConsecutiveAlt(std::vector<int>& nums) {
        std::unordered_map<int, int> map;

        int result = 0;
        for (const auto num : nums) {
            if (!map[num]) {
                int l_bound = map[num - 1];
                int r_bound = map[num + 1];
                int seq_len = l_bound + r_bound + 1;

                map[num] = seq_len
                // Update sequence at bounds
                map[num - l_bound] = seq_len;
                map[num + r_bound] = seq_len;
                result = std::max(result, seq_len);
            }
        }
    }

    int longestConsecutiveSetAlt(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());

        int result = 0;
        for (int num : nums) {
            if (!set.contains(num - 1)) {
                int curr = num;
                int seq_len = 1;
                while (set.contains(curr + 1)) {
                    ++curr;
                    ++seq_len;
                }
                result = std::max(result, seq_len);
            }
        }
        return result;
    }
};
