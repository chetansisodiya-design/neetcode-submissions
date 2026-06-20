class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int strLen = 0;
        for(int i = 0; i< strs[0].size(); i++) {
            char charToCompare = strs[0][i];
            bool isLastCharEqual = true;
            for(int j = 1; j< strs.size(); j++) {
                const string& currentStr = strs[j];

                if(i == currentStr.size() || charToCompare != currentStr[i]) {
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