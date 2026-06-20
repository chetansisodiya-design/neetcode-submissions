class Solution {
public:
////// 0/1 KnapSack
    int coinChange(vector<int>& coins, int amount) {

        int minCoin = dfs(coins, amount, 0);
        if(minCoin == INT_MAX) {
            return  -1;
        }
        return minCoin;
    }

    int dfs(vector<int>& coins, int amount, int index) {
        // For 0  amount we need 0 coin
        if(amount == 0) return 0;
        if(index >= coins.size() || amount< 0) return INT_MAX;
        ///if(amount < 0) return INT_MAX;

        //int res = INT_MAX;

        // Option1: Choose the coin. Future call can again chose the same coin
        int take = INT_MAX;
        int res = dfs(coins, amount-coins[index], index);
        if(res != INT_MAX) {
            take = res+1;
        }

        // Option2: Ignore the coin. Future call wont select same call again
        int ignore = dfs(coins, amount, index+1);

        return min(take, ignore);
    }
};
