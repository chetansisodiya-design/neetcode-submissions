class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> H;

        for(const auto& word: strs) {
            string temp = word;
            sort(temp.begin(), temp.end());

            H[temp].push_back(word);
        }

        vector<vector<string>> result;
        /*
        for(auto &p: H) {
            result.push_back(p.second);
        }*/

        // Map H is about to go away so better to steal the vector rather then copy
        for(auto& [key, group] : H) {
            result.push_back(std::move(group));
        }
        return result;
    }
};
