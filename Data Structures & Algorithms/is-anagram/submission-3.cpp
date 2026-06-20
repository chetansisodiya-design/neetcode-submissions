class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frequency(26, 0);

        for(auto c: s) {
            frequency[c-'a']++;
        }

        for(auto c: t) {
            frequency[c-'a']--;
        }        

        for(auto c: frequency) {
            if(c != 0) {
                return false;
            }
        }
        return true;
    }
};
