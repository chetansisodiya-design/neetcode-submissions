class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        vector<int> num1(nums.begin(), nums.end()-1);    
        vector<int> num2(nums.begin()+1, nums.end()); 

        return max(helper(num1), helper(num2));
    
    }

    int helper(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];        
        int last2 = nums[0];
        int last1 = max(nums[0],nums[1]);

        for(int i = 2; i< nums.size(); i++) {
            int currentTotal = max(last1, nums[i]+last2);
            // now last1 will become last2
            // currentTotal will become last1
            //we will ditch last2.. we dont need that now
            last2 = last1;
            last1 = currentTotal;
        }
        return last1;
    }
};
