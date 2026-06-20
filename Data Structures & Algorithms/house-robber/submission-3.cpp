class Solution {
public:
    int rob(vector<int>& nums) {
        

        // Buttom UP.
        // at index i we have option to rob i or not rob i
        // if rob I - then total = current + (i-2)
        // if not rob I - then total = (i-1)
        // chose max of both

        vector<int> res(nums.size(), 0);
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);

        for(int i = 2; i< nums.size(); i++) {
            res[i] = max( res[i-1], nums[i]+ res[i-2]);
        }
        return res[nums.size()-1];
    }
};
