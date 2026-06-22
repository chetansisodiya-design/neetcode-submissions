class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> store;
        vector<int> result;

        for(int i = 0; i< nums.size(); i++) {
            store.push_back({nums[i] , i});
        }

        sort(store.begin(), store.end());

        int i = 0; int j = nums.size()-1;

        while(i < j) {
            if((store[i].first + store[j].first) < target) {
                i++;
            } else if ((store[i].first + store[j].first) > target) {
                j--;
            } else {
                return {    min(store[i].second, store[j].second), 
                            max(store[i].second, store[j].second)
                        };

            }
        }
        return result;
    }
};
