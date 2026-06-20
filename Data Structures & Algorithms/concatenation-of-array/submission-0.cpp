class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;

        for(auto n: nums) {
            result.push_back(n);
        }

        for(auto n: nums) {
            result.push_back(n);
        }

        return result;
    }
};