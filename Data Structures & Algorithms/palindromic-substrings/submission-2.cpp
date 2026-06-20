class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count{};
        vector<vector<bool>>DP (n, vector<bool>(n, false));
        for(int i = n-1; i>= 0; i--) {
            for(int j = i; j< n ; j++) {
                if(s[i] == s[j] && ((j-i <=2 || DP[i+1][j-1] == true))) {
                    DP[i][j] = true;
                    count++;
                }
            }
        }   
        return count;
    }
};
