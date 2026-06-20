class Solution {
public:
    int numDecodings(string s) {
        return dfs(0, s);
    }

    int dfs(int i,  string& s) {
        if(i == s.size()) {
            // eaching till end ound valid decoding 
            return 1;
        }
        if(s[i] == '0') {
            return 0;
        }

        // selected index not check for remainig string
        int res = dfs(i+1, s);

        // SELECT  2 DIGIT NUMBER NOW
        if(i < s.size()-1) {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7')) {
                res = res + dfs(i+2, s);
            }
        }
        return res;
    }
};
