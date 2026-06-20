class Solution {
public:
//// MEMOIZATION
// in recursion version only index is getting changed. So 1D array is enough
    vector<int> T;
    bool wordBreak(string s, vector<string>& wordDict) {
        T.resize(s.size(), -1);
        return solve(0, s, wordDict);
    }
    int solve(int i, const string& s, vector<string>& wordDict) {
        if(i == s.size()) {
            // reached end of the word means we can broke it successfully as per dict
            return true;
        }
        if(T[i] != -1) return T[i];

        // loop over each word in wordDict and match with s.
        // if match then jump to next index in s and match remaining string with dict
        for(const auto w: wordDict) {
            int len = w.length();
            if(i+len <= s.size() && s.compare(i,len, w) == 0) {
                // word matched
                if(solve(i+len, s, wordDict)) {
                    return T[i] = 1;
                }
            }
        }
        return T[i] = 0;
    }
};
