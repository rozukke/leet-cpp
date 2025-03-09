// NOTE: Do not forget for DP: THE INPUT IS STILL THERE!!

#include <queue>
#include <vector>

using pair_t = std::pair<int, int>;

class Solution {
public:
    // Solution: DP. O(n) time complexity (as if e.g. one large input is in front of smaller increasing ones)
    // i.e. 11, 10, 1, 2, 3, 4; it's still O(n) as traversing all the small values will only have to be done
    // once (for the number 10) and the number 11 will only have to make 2 steps to get to the end.
    // O(n) space complexity (but only using the output memory)
    std::vector<int> dailyTemperaturesDP(const std::vector<int>& temperatures) {
        std::vector<int> result;
        result.resize(temperatures.size());

        // Skip last element as it is always 0
        for (int i = temperatures.size() - 2; i >= 0; --i) {
            // Hack to continue outer loop
            bool cpp_fucking_sucks = false;
            int tracker = i + 1;

            // Find higher temp
            while (temperatures[tracker] <= temperatures[i]) {
                // No higher temperature available
                if (result[tracker] == 0) {
                    cpp_fucking_sucks = true;
                    break;
                }
                // Go to next higher temperature
                tracker += result[tracker];
            }
            if (cpp_fucking_sucks) continue;

            // Distance between temps - if the immediate next is bigger,
            // no iterations of the while happen and tracker is bigger by 1
            // by default.
            result[i] = tracker - i;
        }

        return result;
    }

    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        int size = temperatures.size();

        std::vector<int> result;
        result.resize(size);

        std::vector<int> stack;

        for (int i = size - 1; i >= 0; --i) {
            if (stack.empty()) {
                stack.push_back(i);
                continue;
            }

            // Remove all smaller temperatures
            while (!stack.empty() && temperatures[stack.back()] <= temperatures[i])
                stack.pop_back();

            if (!stack.empty()) result[i] = stack.back() - i;

            stack.push_back(i);
        }

        return result;
    }

    // Solution: priority queue. Slow O(n log n) due to queue insertion.
    std::vector<int> dailyTemperaturesQueue(const std::vector<int>& temperatures) {
        // priority queue containing temperature and corresponding index 
        std::priority_queue<pair_t, std::vector<pair_t>, std::greater<pair_t>> queue;
        std::vector<int> result;
        result.resize(temperatures.size());

        for (int i = 0; i < temperatures.size(); ++i) {
            int curr_temp = temperatures[i];
            if (queue.empty()) {
                queue.emplace(std::make_pair(curr_temp, i));
                continue;
            }

            auto [curr_min, idx] = queue.top();
            if (curr_temp > curr_min) {
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

            queue.emplace(std::make_pair(curr_temp, i));
        }
        return result;
    }
};
