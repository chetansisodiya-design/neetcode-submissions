class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1);
        // base
        dp[n] = 1;

        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0') {
                dp[i] = 0;
            } else {
            
                dp[i] = dp[i+1];
                // PS its not 1+dp[i+1] 
                //If dp[i+1] (the string "2345") has 3 different ways to be decoded, then by picking '1', you now have 3 ways to decode "12345". You didn't create a 4th way; you just extended the existing 3 ways.
            
                if(i < s.size()-1 && (s[i]== '1' || (s[i] == '2' && s[i+1] < '7'))) {
                    dp[i] = dp[i] + dp[i+2];
                }
            }
        }
        return dp[0];
    }
};
