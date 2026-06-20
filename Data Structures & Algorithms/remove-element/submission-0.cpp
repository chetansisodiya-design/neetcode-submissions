class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(i = 0; i< nums.size(); i++) {
            if(val == nums[i]) {
                /// i need to replaced. 
                int j = i+1;
                while(j < nums.size() && nums[i] == nums[j]) {
                    j++;
                }
                // here i & j need to repalced
                if(j < nums.size()) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                } else {
                    break;
                }
                
            }
        }
        return i;
    }
};