class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> result;
        for(int i = 0; i< nums.size(); i++) {
            if(seen.count(target-nums[i])) {
                result.push_back(seen[target-nums[i]]);
                result.push_back(i);
                return result;
            } else {
                seen[nums[i]] = i;
            }
        }
        return result;
    }
};
