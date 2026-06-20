class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int strLen = 0;
        for(int i = 0; i< strs[0].size(); i++) {
            char charToCompare = strs[0][i];
            for(int j = 1; j< strs.size(); j++) {
                // Use a reference to avoid costly string copies!
                const string& currentStr = strs[j];

                // If index 'i' exceeds current string's length or characters don't match
                if(i == currentStr.size() || charToCompare != currentStr[i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        // Agar poora loop khatam ho gaya, matlab pehli string hi prefix hai
        return strs[0];
    }
};