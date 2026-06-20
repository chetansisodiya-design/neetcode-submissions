class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        //last1 (representing the max profit up to the second house) should actually be 10 (from robbing house 0), not 1
        int last2 = nums[0];
        int last1 = max(nums[1], nums[0]);

        // as we mpve forward we keep on calcualting  valules
        // So is i want to calculate result at i location
        // result = max(last1, last2+nums[i])
        // now this result will become last 1
        // last1 will become last 2. 
        // last2 will be discarded

        for(int i = 2; i< nums.size(); i++) {
            int currentMax = max(last1, last2+nums[i]);
            last2 = last1;
            last1 = currentMax;
        }
        return last1;
    }
};
