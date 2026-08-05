class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      // Store the last index of each character
        unordered_map<char, int> mp;
        int left=0;      // Left pointer of the sliding window
        int maxLen=0;    // Maximum length found
        // Expand the window using the right pointer
        for(int right=0;right<s.length();right++){
            // If the character is already in the current window,
            // move the left pointer just after its previous occurrence
            if(mp.find(s[right])!=mp.end() && mp[s[right]]>=left){
                left=mp[s[right]]+1;
            }
            // Update the last seen index of the current character
            mp[s[right]]=right;
            // Update the maximum window length
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};