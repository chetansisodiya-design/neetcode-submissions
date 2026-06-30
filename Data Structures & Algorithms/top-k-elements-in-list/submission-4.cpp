class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> H;

        for(auto num: nums) {
            H[num]++;
        }
        vector<vector<int>> bucket (nums.size() + 1);

        for(const auto& [key, count] : H) {
            bucket[count].push_back(key);
        }
        vector<int> res;
        res.reserve(k);
        for(int i = bucket.size()-1; i >= 0 && res.size() < k; i--) {
            for(auto num: bucket[i]) {
                res.push_back(num);
                if(res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
