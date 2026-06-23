class Solution {
public:
    struct ArrayHasher {
        std::size_t operator()(const std::array<int, 26>& a) const {
            std::size_t h = 0;
            for (int e : a) {
                // The classic boost::hash_combine magic number
                h ^= std::hash<int>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<array<int, 26>, vector<string>, ArrayHasher> res;

        for(const auto& word: strs) {
            // we can make keys from tje letter of this word
            //vector<int> count(26, 0);
            array<int, 26> count = {0};
            for(char c: word) {
                count[c - 'a']++;
            }
            
            res[count].push_back(word);
        }
        vector<vector<string>> result;
        result.reserve(res.size());
        for(const auto& [key, group] : res) {
            result.push_back(std::move(group));
        }
        return result;
    }
};
