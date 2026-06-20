/*class Solution {
public:
////// 0/1 KnapSack
    //vector<vector<int>>(coins.size()+1, vector<int>(amount+1), -1);
    vector<vector<int>> T;
    int coinChange(vector<int>& coins, int amount) {

        T.assign(coins.size(), vector<int>(amount + 1, -1));
        

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
        if(T[index][amount]!= -1) return T[index][amount];
        //int res = INT_MAX;

        // Option1: Choose the coin. Future call can again chose the same coin
        int take = INT_MAX;
        int res = dfs(coins, amount-coins[index], index);
        if(res != INT_MAX) {
            take = res+1;
        }

        // Option2: Ignore the coin. Future call wont select same call again
        int ignore = dfs(coins, amount, index+1);

        return T[index][amount] = min(take, ignore);
    }
};
*/

class Solution {
public:
////// 0/1 KnapSack
    //vector<vector<int>>(coins.size()+1, vector<int>(amount+1), -1);
    vector<vector<int>> T;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> T(n+1, vector<int>(amount+1));
        int MAX = amount+11;
      
        // Base Case: To make amount 0, we always need 0 coins
        for(int i = 0; i<= coins.size() ; i++) {
            T[i][0] = 0;
        }
        // Base Case 2: Impossible to make amount > 0 with 0 coins
        for(int j = 1; j <= amount; j++) {
            T[0][j] = MAX;
        }
        
        for(int i = 1; i<= n; i++) {
            for(int j = 1; j<= amount; j++) {
                
                if(coins[i-1] <= j) {
                    // we have option to chose
                    int op1 = T[i-1][j];

                    int op2 = 1+ T[i][j-coins[i-1]];

                    T[i][j] = min(op1, op2);
                } else {
                    T[i][j] = T[i-1][j];
                }
            }
        }
        // If the result is still MAX, it means the amount is unreachable
        return (T[n][amount] >= MAX) ? -1 : T[n][amount];
    }
};

