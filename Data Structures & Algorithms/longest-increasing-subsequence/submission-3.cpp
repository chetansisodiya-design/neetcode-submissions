class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       // Loop from 0 to n 
       // keep track of prev indx which was picked. 
       // if picked update index and prevIndex in next call
       // if not picked dont update index
        // for first elemtn pick prevIndex = -1

        return solve(nums, 0, -1);
    }

    int solve(vector<int>& nums, int index, int prevIndex) {
        // BC
        if(index == nums.size())  {
            return 0;
        }

        // Dont include
        int skip = solve(nums, index+1, prevIndex);

        // we can includene when value greater then prev Index
        int take {};
        if(prevIndex == -1 || nums[prevIndex] < nums[index]) {
            take =  1+solve(nums, index+1, index);
        }
        return max(skip, take);
    }
};
