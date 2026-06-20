class Solution {
public:
    int characterReplacement(string s, int k) {
       int maxLen = 0;
       int maxFrequency = 0;
        unordered_map<char, int> H;
       int l = 0;
       for(int r = 0; r < s.size(); r++) {
        H[s[r]]++;
        maxFrequency =  max(maxFrequency, H[s[r]]);

        // lenth - maxFreq <= k (valid window)
        // length - maxFreq > k (invalid window)
        while(((r-l+1) - maxFrequency) > k) {
            // reduce window
            H[s[l]]--;
            maxFrequency = max(maxFrequency, H[s[l]]);
            l++;
        }
        // valid window
        maxLen = max(maxLen, (r-l+1));
       } 
       return maxLen;
    }
};
