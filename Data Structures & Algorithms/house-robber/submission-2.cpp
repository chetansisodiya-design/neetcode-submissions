class Solution {
public:
    vector<int> res;
    int rob(vector<int>& nums) {
        //start i =0
        //rob house num[i] + solve(i+1)
        // TLE Exception
        res.resize(nums.size(), -1);
        return solve(0,nums);
    }

    int solve(int index, vector<int>& nums) {
        if(index >= nums.size()) {
            // house beyond array have 0 money
            return 0;
        }

        if(res[index] != -1) return res[index];
        // 2 option : 
        // option1: skip current house and rob next one. 
        // option2: rob current house and then rob next to next 
        // money robbed. = current House Money + future House Money from recursion call
        return res[index] = max(solve(index+1, nums) , nums[index] + solve(index+2, nums));
    }
};
