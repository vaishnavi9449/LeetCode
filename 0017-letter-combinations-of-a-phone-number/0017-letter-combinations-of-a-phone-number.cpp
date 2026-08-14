class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string current;
        function<void(int)> backtrack = [&](int index) {
            // If we have processed all digits
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
            // Get letters corresponding to current digit
            string letters = mapping[digits[index] - '0'];
            // Try every possible letter
            for (char ch : letters) {
                current.push_back(ch);
                // Move to next digit
                backtrack(index + 1);
                // Remove the last character
                current.pop_back();
            }
        };
        backtrack(0);
        return result;
    }
};