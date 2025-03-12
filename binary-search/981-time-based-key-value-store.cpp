#include <unordered_map>
#include <vector>

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;

public:
    TimeMap() {}

    void set(const std::string& key, const std::string& value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }

    std::string get(const std::string& key, int timestamp) {
        auto& values = map[key];
        int left = 0;
        int right = values.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first > timestamp) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right >= 0 ? values[right].second : "";
    }
};
