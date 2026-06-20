/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l = 0;
        int r = 0;
        for(;r < prices.size(); r++) {
            maxProfit = max( maxProfit, prices[r] - prices[l]);

            if(prices[r] < prices[l]) {
                l = r;
                // DOnt ineremnt r here because for loop incrementing it
                //r = l+1;
            } 
        }
        return maxProfit;
    }
};
*/
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
            } 
            r++;
        }
        return maxProfit;
    }
};
