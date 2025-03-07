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
