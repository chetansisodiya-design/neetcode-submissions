class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        //Solution1: 
        // Using array.. When someone true another - his score goes down
        // When somone is trusted .. his score will go up.
        // For n people -  a judge is trusted by all.. and judge trust no one.
        // So for judge the trust score should be exactly n-1
        // create adjency matrix

        // If there's only one person and no trust relationships, they are the judge        
        if (trust.empty() && n == 1) return 1;

        vector<int> trustScore(n+1,0);
        map<int, vector<int>> gp;

        for(auto &t: trust) {
            int u = t[0];
            int v = t[1];
            // this person trusting someone . So decrement
            trustScore[u] = trustScore[u]-1;  

            //v is trusted by u.. So increment trust score of v
            trustScore[v] = trustScore[v]+1;
        }
        // not check if any index have exactly n-1 value
        // we are checking for n people.. so we create array for n+1.
        // So go till i <= n (not i< n)
        for(int i = 1; i<=n;i++) {
            if(trustScore[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};