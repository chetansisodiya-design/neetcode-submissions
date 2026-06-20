class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suffix_max = INT_MIN;
        int prefix_max = INT_MIN;
        int curr = 1;
        for(int i =0; i< nums.size(); i++) {
            curr = curr*nums[i];
            prefix_max = max(prefix_max, curr);
            if(nums[i] == 0) {
                curr = 1;
            }
        }
        curr =1;
        for(int i = nums.size()-1; i>=0 ; i--) {
            curr = curr*nums[i];
            suffix_max = max(suffix_max, curr);
            if(nums[i] == 0) {
                curr = 1;
            }
        }
        return max(prefix_max,suffix_max);
    }
};
