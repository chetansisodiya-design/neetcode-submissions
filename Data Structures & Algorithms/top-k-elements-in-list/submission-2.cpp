class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> H;

        for(auto num: nums) {
            H[num]++;
        }

        // array index as frequenct and value as the nums array value. 
        // max index can nums.size()
        // nums = [4,4,4,4,4,4] , n = 6, we need array with index 6.. So len = nums.size()+1
        // nums = [4,4,4,5,5,5] == (3 -> [4,5]) we need vector of vector
        vector<vector<int>> A(nums.size()+1);

        for(auto pair: H) {
            // pair.first = value
            // pair.second = frequence
            A[pair.second].push_back(pair.first);
        }

        // we have a array.. Higher freq will go to high index So traverse from back
        vector<int> result;
        for(int i = A.size()-1; i>=0; i--) {
            for(int n: A[i]) {
                result.push_back(n);
                if(result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
