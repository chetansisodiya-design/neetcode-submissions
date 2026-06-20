class Solution {
public:
    vector<vector<int>> res;
    int rob(vector<int>& nums) {
        // you can not rob last house if you robbed 1st one
        // you can rob last house if you have not robbed 1st one
        // passing flag = true if house 1 is robbed
        // MEMOIZATION
        if(nums.size() == 1) return nums[0];
        res.resize(nums.size(), vector<int>(2, -1));
        return max(dfs(0, true, nums), dfs(1, false, nums));
    }

    int dfs(int index, bool flag, vector<int>& nums) {
        if(index >= nums.size()) {
            return 0;
        }
        // last house is nums.size()-1
        if(flag == true && index == nums.size()-1) {
            return 0;
        }
        if(res[index][flag] != -1) {
            return res[index][flag];
        }

        return res[index][flag] = max( dfs(index+1, flag, nums), nums[index]+dfs(index+2, flag, nums));
    }
};
