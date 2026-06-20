class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxLen = 0;
        for(int i = 0; i< s.size(); i++) {
            unordered_map<char, int> H;
            int maxFreq = 0; 
            for(int j = i; j< s.size(); j++) {
                H[s[j]]++;
                maxFreq = max(maxFreq, H[s[j]]);
                
                int numOfChange = (j-i+1) - maxFreq;
                if(numOfChange <= k) {
                    maxLen = max(maxLen, (j-i+1));
                } else {
                    break;
                }
            }
        } 
        return maxLen;
    }
};
