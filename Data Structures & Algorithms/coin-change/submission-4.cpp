class Solution {
public:
    vector<int> T;
    int coinChange(vector<int>& coins, int amount) {
        T.resize(amount+1, -1);
        int minCoin = dfs(coins, amount);
        if(minCoin == INT_MAX) {
            return  -1;
        }
        return minCoin;
    }
    int dfs(vector<int>& coins, int amount) {
        // For 0  amount we need 0 coin
        if(amount == 0) return 0;
        int res = INT_MAX;

        if(T[amount] != -1) {
            return T[amount];
        }
        // We have option from select all the coin again and again
        // Soo loop whole array
        for(int coin: coins) {
            if((amount - coin) >= 0) {
                // we still some some amount left to calculate
                int result = dfs(coins, amount - coin);
                if(result !=INT_MAX) {
                    T[amount] = res = min(res, 1+result);
                }
            } 
        }
        return T[amount] = res;
    }
};
