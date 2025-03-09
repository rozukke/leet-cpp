#include <stack>

class MinStack {
public:
    void push(int val) {
        values.push(val);
        if (minimums.size() == 0 || val <= minimums.top()) {
            minimums.push(val);
        }
    }

    void pop() {
        int val = values.top();
        values.pop();
        if (val == minimums.top()) {
            minimums.pop();
        }
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return minimums.top();
    }
private:
    std::stack<int> minimums{};
    std::stack<int> values{};
};


class MinStack {
public:
    void push(int val) {
        if (pairs.empty()) {
            pairs.push({val, val});
            return;
        }
        auto [_, min] = pairs.top();
        int new_min = std::min(min, val);
        pairs.push({val, new_min});
    }

    void pop() {
        pairs.pop();
    }

    int top() {
        return pairs.top().first;
    }

    int getMin() {
        return pairs.top().second;
    }

private:
    std::stack<std::pair<int, int>> pairs;
};
