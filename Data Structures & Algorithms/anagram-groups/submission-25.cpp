class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> res;

        for(const auto& word: strs) {
            // we can make keys from tje letter of this word
            vector<int> count(26, 0);
            for(char c: word) {
                count[c - 'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 1; i< 26; i++) {
                key += ',' + to_string(count[i]);
            }
            
            res[key].push_back(word);
        }
        vector<vector<string>> result;
        for(const auto& [key, group] : res) {
            result.push_back(std::move(group));
        }
        return result;
    }
};
