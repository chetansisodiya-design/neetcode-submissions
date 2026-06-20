class Solution {
public:
    int countSubstrings(string s) {
        
        int count {};
        
        // odd length
        for(int index =0; index< s.size(); index++) {
            int i = index;
            int j = index;
            while(i>=0 && j< s.size() && s[i] == s[j]) {
                // this is palindroom now
                count++;
                i--; j++;
            }
            // even length
            i = index;
            j = index+1;
            while(i>=0 && j< s.size() && s[i] == s[j]) {
                // this is palindroom now
                count++;
                i--; j++;
            }
        }
        return count;
    }
};
