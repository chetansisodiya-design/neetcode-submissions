class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> H;

        for(auto num:nums) {
            H[num]++;
        }

        vector<vector<int>> freq(nums.size()+1);

        for(const auto& [key, value] : H) {
            freq[value].push_back(key);
        }
        vector<int> result;
        for(int i = freq.size()-1; i > 0; i--) {
            for(int n: freq[i]) {
                result.push_back(n);
            }
            if(result.size() == k) {
                return result;
            }
        }
        return result;
    }
};
