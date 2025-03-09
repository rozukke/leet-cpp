#include <queue>
#include <vector>

using pair_t = std::pair<int, int>;

class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        // priority queue containing temperature and corresponding index 
        std::priority_queue<pair_t, std::vector<pair_t>, std::greater<pair_t>> queue;
        std::vector<int> result;
        result.resize(temperatures.size());

        for (int i = 0; i < temperatures.size(); ++i) {
            int curr_temp = temperatures[i];
            if (queue.empty()) {
                queue.push(std::make_pair(curr_temp, i));
                continue;
            }

            auto [curr_min, idx] = queue.top();
            if (curr_temp >= curr_min) {
                // update past temperatures
                while (!queue.empty()) {
                    auto [curr_min, idx] = queue.top();
                    if (curr_min < curr_temp) {
                        result[idx] = i - idx;
                        queue.pop();
                    } else {
                        break;
                    }
                }
            }
            queue.push(std::make_pair(curr_temp, i));
        }
        return result;
    }
};

int main() {
    Solution a;
    auto thing = a.dailyTemperatures({73,74,75,71,69,72,76,73});
    for (auto th: thing) {
        std::cout << th << " ";
    }
    std::cout << "Done!" <<std::endl;
}
