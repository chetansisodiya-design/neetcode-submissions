class Solution {
public:
/// Brute Force
    string longestPalindrome(string s) {
        string res = "";
        int len = 0;
        for(int i = 0; i< s.size(); i++) {
            for(int j = i; j< s.size(); j++) {
                int l = i, r = j;

                while(l < r && s[l] == s[r]) {
                    l++;
                    r--;
                }

                if(l >= r && len < (j-i+1)){
                    res = s.substr(i, j-i+1);
                    len = j-i+1;
                }
            }
        }
        return res;
    }
};