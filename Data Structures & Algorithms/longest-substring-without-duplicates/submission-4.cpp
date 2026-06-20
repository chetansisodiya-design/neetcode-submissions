class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> seen;
        int l = 0; int r = 0; int maxLen = 0;
        for(int r = 0; r < s.size(); r++) {
            // 1. While the current character is a duplicate...
            while(seen.count(s[r])) {
                // 2. Shrink the window from the left
                seen.erase(s[l]);
                l++;
            }
            // 3. Now it's safe to add the character
            seen.insert(s[r]);
            // 4. The window [l...r] is guaranteed to be unique
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
