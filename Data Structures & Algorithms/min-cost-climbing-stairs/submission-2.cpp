class Solution {
    vector<int>memo;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(), -1);
    // MEMOIZATION SOLUTION RETURN VALUDE from function
    return min(findCost(0, cost), findCost(1, cost));
    }

    int findCost(int index, vector<int>& cost) {
        // when index >= cost.sixe()
        // cost of to reach top is 0
        if(index >= cost.size()) {
            return 0;
        }
        if(memo[index] != -1) 
            return memo[index];

        // Min cost from  index  to reach top
        // cost at index + min from future call

        return  memo[index] = cost[index] + min(findCost(index+1, cost), findCost(index+2, cost));
    }
};
