// Solution: use bucket sort to store frequencies in a way where they do not have to be sorted.
// Using an array the size of the input, store each input using the frequency of the input
// (calculated using a hash map) as the index into the array. Since frequencies can repeat,
// each element of the array must be a vector.
// This array can be traversed backwards to find the top k most frequent elements.
// Requires average O(n) space complexity (at least an empty vector per input) and O(n)
// time complexity (all numbers iterated, and up to all frequencies iterated).
// Somewhat insane, however.
//
// Naive: use a hashmap to count frequencies for each item, and then sort the kv pairs by the frequency,
// grabbing the first k of the sorted list.
// O(n log n) time complexity, O(n) space complexity.

#include <unordered_map>
#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>

using KV = std::pair<int, int>;

class Solution {
public:
    std::vector<int> topKFrequentNaive(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map{};

        // Collect frequencies
        for (const auto num : nums) {
            map[num]++;
        }

        auto map_vals = std::vector<KV>(map.begin(), map.end());
        std::sort(map_vals.begin(), map_vals.end(), [](KV a, KV b) {a.second > b.second});

        auto result = std::vector<int>{};
        result.reserve(k);
        for (int i = 0; i < k; ++i) {
            result.push_back(map_vals);
        }
        return result;
    }

    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map{};
        for (const auto n : nums) {
            map[n]++;
        }

        std::vector<std::vector<int>> freq(nums.size() + 1);
        for (auto const& [key, value] : map) {
            freq[value].push_back(key);
        }

        std::vector<int> result;
        result.reserve(k);
        for (int i = freq.size() - 1; i >= 0; --i) {
            for (const auto num : freq[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            } 
        }
        return {};
    }
};
