
//// Take the middle element and expand in both direction 
class Solution {
public:

    string longestPalindrome(string s) {
        string res;
        int len = INT_MIN;
        int start_index = 0;
        for(int index = 0; index < s.size(); index++) {

            // odd palindrom
            int i = index; 
            int j = index;
            while(i>=0 && j < s.size() && s[i] == s[j] ) {
                if(len < (j-i+1)) {
                    len = j-i+1;
                    start_index = i;

                }                
                // means panlindrom
                i--; j++;
            }


            i = index; j = index+1;
            while(i>=0 && j< s.size() && s[i] == s[j] ) {
                if(len < (j-i+1)) {
                    len = j-i+1;
                    start_index = i;

                }                
                i--; j++;
            }

        }
        
        return res = s.substr(start_index, len);
;
    }
};
