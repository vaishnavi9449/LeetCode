
class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        int freq[26] = {0};

        // Count characters in s
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Decrease frequency using characters of t
        for (int i = 0; i < t.length(); i++) {
            freq[t[i] - 'a']--;
        }

        // Check if all frequencies are zero
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
