class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> H;
        for(int i =0; i < nums.size(); i++) {
            H[nums[i]] = i;
        }
        vector<int> res;
        for(int i = 0; i< nums.size(); i++) {
            if(H.contains(target - nums[i]) && H[target - nums[i]] != i) {
                int index1 = i;
                int index2 = H[target - nums[i]];
                if(index1 <= index2) {
                    res.push_back(index1);
                    res.push_back(index2);
                    break;
                } else {
                    res.push_back(index2);
                    res.push_back(index1); 
                    break;
                }
            } 
        }
        return res;
    }
};
