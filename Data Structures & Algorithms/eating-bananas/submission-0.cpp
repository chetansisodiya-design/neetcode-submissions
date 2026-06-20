class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int p: piles) {
            r = max(r, p);
        }

        // l and r is the rance where answe lie.. We will do binary search on this range
        int ans = r;
        while(l <= r) {
            int mid = l + (r-l)/2;

            // Safety check: mid 0 nahi hona chahiye
            if (mid == 0) {
               // l = 1;
                //continue;
            }

            long long totalHours = 0;

            for(int p: piles) {
                // p ko double mein cast karna zaroori hai 
                // taaki floating point division ho (e.g., 7.0 / 3.0 = 2.33)
                totalHours += (long long)std::ceil((double)p / mid);
            }
            if(totalHours <= h) {
                // Agar time ke andar kha liya, toh ye speed possible hai
                // Lekin humein MINIMUM speed chahiye, toh left mein dhoondo
                ans = mid;
                r = mid - 1;   
            } else {
                // total hours abhi H se bhi jyada hai.. matlab we can increase the speed.
                // So we will righ side because udhar more speed hai.
                l = mid + 1;
            }
        }
        return ans;
        
    }
};
