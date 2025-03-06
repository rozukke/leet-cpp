class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int key[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            key[s[i] - 'a'] += 1;
            key[t[i] - 'a'] -= 1;
        }

        for (int i = 0; i < 26; ++i) {
            if (key[i] != 0) return false;
        }
        return true;
    }
};
