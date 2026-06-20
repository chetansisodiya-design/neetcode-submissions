class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Initialize with the first element
        int max_prod = nums[0];
        int min_prod = nums[0];
        int result = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            int val = nums[i];

            // If negative, the potential for max and min swaps
            if (val < 0) {
                swap(max_prod, min_prod);
            }

            // Choice: Start a new subarray at 'val' OR extend the existing one
            // We use temp variables or compute carefully to avoid using updated values
            max_prod = max(val, max_prod * val);
            min_prod = min(val, min_prod * val);
            
            // Update the global answer
            result = max(result, max_prod);
        }
        return result;
    }
};