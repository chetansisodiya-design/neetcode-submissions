class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        if(n==0) return 0;
        int maxLen = INT_MIN;

        unordered_map<char, int> H;

        int l = 0; 

        for(int r = 0; r < n ; r++){

            if(H.contains(s[r])) {
                l = max(l,H[s[r]] +1);
            }
            int len = r-l+1;
            maxLen = max(maxLen, len);
            H[s[r]] = r;

        }
        return maxLen;
    }
};
