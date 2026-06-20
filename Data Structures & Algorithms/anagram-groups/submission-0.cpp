class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // sort allthe string and enterin map. with actual string as array on string in value
        unordered_map<string, vector<string>> H;
        for(int i = 0; i< strs.size(); i++) {
            string str = strs[i];
            string temp = str;
            sort(temp.begin(), temp.end());
            H[temp].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& pair: H) {
            result.push_back(pair.second);
        }
        return result;
    }
};
