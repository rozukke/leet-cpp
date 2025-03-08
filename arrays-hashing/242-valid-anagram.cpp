// Solution: use a "key" to take a hash of the algorithm by counting letter frequencies
// for each of the two words, subtracting for one, and adding for the other.
// If all values in the key are zero, the two words are equal.
// Requires O(1) memory (array of length 26) and O(n) time complexity (whole word must be iterated).
//
// Naive: sort the words and verify that they are equal for (ideally) O(n log n) time complexity and
// implementation dependent space compleixity.

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
