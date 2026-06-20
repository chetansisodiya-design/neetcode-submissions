class Solution {
public:
    // MEMOIZATION
    //index going from 0 tp n-1. So I row = n (where n-1 is last row in DP)
    // prevIndex goinf from -1 to n-1.. 
    // So for -1 index i will is 0. For index 1 i will use column 1+1 = 2 
    // for n-1 i will use index n. So column = n+1;

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> DP(n, vector<int>(n+1, -1));
        // Solve(index, prevIndex)
        //== LIS starting at index with prevIndex

       // Loop from 0 to n 
       // keep track of prev indx which was picked. 
       // if picked update index and prevIndex in next call
       // if not picked dont update index
        // for first elemtn pick prevIndex = -1

        return solve(nums, 0, -1, DP);
    }

    int solve(vector<int>& nums, int index, int prevIndex, vector<vector<int>>& DP) {
        // BC
        // index reached in last - means all element exhausted. 
        // Function cant give you any LIS now. So return 0;
        if(index == nums.size())  {
            return 0;
        }

        if(DP[index][prevIndex+1] != -1) {
            return DP[index][prevIndex+1];
        }
        // Dont include
        int skip = solve(nums, index+1, prevIndex, DP);

        // we can includene when value greater then prev Index
        int take {};
        if(prevIndex == -1 || nums[prevIndex] < nums[index]) {
            take =  1+solve(nums, index+1, index, DP);
        }
        return DP[index][prevIndex+1] = max(skip, take);
    }
};
