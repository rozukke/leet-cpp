// Solution: use a hash map, with a "hash" of each word in the form of a 26-length frequency array
// as the key to a list of words that are all anagrams. Each word is hashed and stored at the appropriate
// list.
// Requires O(n) space complexity (all words stored in map) and O(n) time complexity (each word hashed).
//
// Naive: store a 2D vector for each group, and for each word, check if the word is an anagram by iterating
// through the vector. If none of them are a match, a new vector is added. The efficency of the anagram check
// is variable between O(n log n) and O(n), while the algorithm itself is O(n^2) (each i in n checks up to index(i)
// values, which is (n^2) / 2, simplifying to O(n^2)). 

#include <unordered_map>
#include <cstdint>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::array<uint8_t, 26>, std::vector<std::string>, ArrayHasher> map{};
        for (auto const& elem : strs) {
            std::array<uint8_t, 26> key{0};
            for (const auto c : elem) {
                key[c - 'a'] += 1;
            }
            if (map.find(key) != map.end()) {
                map[key].emplace_back(elem);
            } else {
                map[key] = {elem};
            }
        }
        std::vector<std::vector<std::string>> result{};
        result.reserve(map.size());
        for (auto const& [_, value] : map) {
            result.emplace_back(std::move(value));
        }
        return result;
    }

    struct ArrayHasher {
        std::size_t operator()(const std::array<uint8_t, 26>& a) const {
            std::size_t hash = 0;

            for (auto elem : a) {
                hash ^= std::hash<int>{}(elem) + 0x93779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
};
