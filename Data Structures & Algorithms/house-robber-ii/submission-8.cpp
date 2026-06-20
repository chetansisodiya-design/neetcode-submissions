class Solution {
public:
    vector<int> res;
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> nums1(nums.begin()+1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()-1);
        
        return max(helper(nums1), helper(nums2));
    }

    int helper(vector<int> nums) {
        //if(nums.empty()) return 0;
        //if(nums.size() == 1) return nums[0];
        vector<int> res(nums.size());

        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        //at index i i am deopend on last1 and last
        // res[i] = max(res[i-1], nums[i]+ res[i-2])
        for(int i = 2; i < nums.size(); i++) {
            res[i] = max(res[i-1], nums[i]+res[i-2]);
        }
        return res[nums.size()-1];
    }
};
