class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> H;

        for(const string& str: strs) {
            vector<int> freq(26, 0);
            for(char c: str) {
                freq[c - 'a']++;
            }

            string key = to_string(freq[0]);
            for(int k = 1; k< 26; k++) {
                key += ','+freq[k];
            }
            H[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto pair: H) {
            result.push_back(pair.second);
        }
        return result;
    }
};
