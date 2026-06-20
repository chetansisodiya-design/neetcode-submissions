class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        // 1D DP Memoization
        /*
        Yes, you absolutely can use 1D memoization, but there is a catch: you have to run the DFS twice on two different slices of the data.

Since the circular constraint only exists between the first and last house, you can break the circle into two linear problems. Each linear problem only requires a 1D memo because there is no "hidden state" (the flag) to keep track of anymore.
        */


        /// CAN NOT USE RESIZE HERE
        if(nums.size() == 1) return nums[0];
        memo.assign(nums.size(), -1);
        int n = nums.size();
        int planA = dfs(0, n-2, nums);
        
        // CAN NOT USE RESIZE HERE
        memo.assign(nums.size(), -1);
        int planB = dfs(1, n-1, nums);

        return max(planA, planB);
    }
    
    int dfs(int i, int end, vector<int>& nums) {
        // end is the allowed index
        if(i>end) {
            return 0;
        }
        if(memo[i] != -1) {
            return memo[i];
        }

        // Decision: Rob current house or skip it
        return memo[i] = max(dfs(i+1, end, nums), nums[i] + dfs(i+2, end, nums));   
    }
};

/*
The reason resize is failing where assign succeeds comes down to how these two functions handle existing data in your memo vector.

When you use memo.assign(n, -1), it does two things:

    Ensures the vector has a size of n.

    Overwrites every single element with -1.

    When you use memo.resize(n, -1), it works differently:

    If the new size is larger than the current size, it adds new elements and initializes only those new elements to -1.

If the new size is the same as the current size, it does nothing to the existing data.

*/