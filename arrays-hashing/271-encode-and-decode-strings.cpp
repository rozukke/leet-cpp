#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string encode(const std::vector<std::string>& strs) {
        std::string res;
        // heuristically average word size + size and delimiter
        res.reserve(strs.size() * (5 + 2));

        for (const auto& str : strs) {
            res.append(std::to_string(str.size()));
            res.push_back(':');
            res.append(str);
        }
        return res;
    }

    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> result;
        result.reserve(s.size() / 7);

        std::size_t idx = 0;
        while (idx < s.size()) {
            std::size_t colon_idx = s.find(':', idx);
            int len = std::stoi(s.substr(idx, colon_idx - idx));
            result.emplace_back(s.substr(colon_idx + 1, len));
            idx = colon_idx + 1 + len;
        }
        return result;

    }
};

int main() {
    Solution a;
    auto encoded = a.encode(std::vector<std::string>{"abcd", "efg", "hijkl", "1234"});
    std::cout << encoded << "\n"
    auto decoded = a.decode(encoded);
    for (auto const& str: decoded) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}
