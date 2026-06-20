class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> T(n+1, -1);

        // set last number a 1 (base condition)
        T[n] = 1;

        return dfs(0, s, T);
    }
    int dfs(int i, string& s, vector<int>&T) {
        if(T[i] != -1) {
            return T[i];
        }
        if(s[i] == '0') {
            return T[i] = 0;
        }

        int res = dfs(i+1, s, T);

        if(i < s.size()-1) {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7')) {
                res += dfs(i+2, s, T);
            }
        }
        return T[i] = res;
    }
};
