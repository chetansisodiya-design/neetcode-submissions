class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> H;

        for(auto n : nums) {
            if(H.contains(n)) {
                return true;
            } else {
                H[n]++;
            }
        }
        return false;
    }
};