class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int strLen = 0;
        for(int i = 0; i< strs[0].size(); i++) {
            char charToCompare = strs[0][i];
            bool isLastCharEqual = true;
            for(int j = 1; j< strs.size(); j++) {
                string str = strs[j];

                if(i == str.size()) {
                    isLastCharEqual = false;
                    break;
                }
                if(charToCompare != str[i]) {
                    isLastCharEqual = false;
                    break;                    
                }
            }
            if(isLastCharEqual == true) {
                strLen++;
            } else {
                break;
            }
        }
        return strs[0].substr(0, strLen);
    }
};