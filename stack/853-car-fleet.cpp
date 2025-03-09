// NOTE: Sorting appears to be a powerful move for stack-based problems. Worth considering if something
// *feels* stack based but is in incorrect order.

class Solution {
public:
    using pair_t = std::pair<int, int>;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // each fleet will be limited by the speed of the slowest car in the fleet
        // iterate backwards through the positions & speeds for each car, incrementing
        // for each next slow car

        std::vector<float> fleets;
        std::vector<pair_t> sorted;

        // Overpowered if the problem otherwise feels impossible
        sorted.reserve(position.size());

        for (int i = 0; i < position.size(); ++i) {
            sorted.emplace_back(position[i], speed[i]);
        }
        std::sort(sorted.begin(), sorted.end());

        // Actual algorithm
        for (int i = position.size() - 1; i >= 0; --i) {
            auto [curr_pos, curr_speed] = sorted[i];
            float time_to_target = float(target - curr_pos) / curr_speed;

            if (stack.empty() || time_to_target > fleets.back()) {
                fleets.push_back(time_to_target);
            }
        }

        return fleets.size();
    }
};
