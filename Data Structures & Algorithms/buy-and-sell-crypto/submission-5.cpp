class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l = 0;
        int r = 0;
        while(r < prices.size()) {
            maxProfit = max( maxProfit, prices[r] - prices[l]);

            if(prices[r] < prices[l]) {
                l = r;
                r = l+1;
            } else {
                r++;
            }
        }
        return maxProfit;
    }
};
