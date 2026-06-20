
/*
📍 Input: strs = ["act", "pots", "tops", "cat", "stop", "hat"]

🏃 Step-by-Step Execution

1. Word: "act"

Count Array: a:1, c:1, t:1 (baaki sab 0).

Key Generation: "1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0"

Map Action: res["1,0,1...1,0"] = ["act"]
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> H;

        for(int i = 0; i< strs.size(); i++) {
            vector<int> freq(26, 0);

            string str = strs[i];
            for(int j = 0; j< str.size(); j++) {
                freq[str[j]-'a']++;
            }
            // createa key now
            string key = to_string(freq[0]);
            for(int k = 1; k< 26; k++) {
                key = key + ","+to_string(freq[k]);
            }
            // insert into map
            H[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto pair: H) {
            result.push_back(pair.second);
        }
        return result;
    }
};
