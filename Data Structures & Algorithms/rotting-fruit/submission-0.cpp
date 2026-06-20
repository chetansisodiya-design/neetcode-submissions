class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // hum log saari bekar fruit wali noted ko collect kar lenge.
        // bekar good fruits ka count save kar lenge/

        // with each BFS level, for each surrounding node  we will decrement count of fresh fruit.
        // when BFS level go one level up we wil increment the timer.

        int timer = 0;
        int freshFruits = 0;
        queue<pair<int,int>> q;
        // 0 empty cell, 1 fresh , 2 soiled
        for(int i = 0; i< grid.size(); i++) {
            for(int j = 0; j< grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    freshFruits++;
                }
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        vector<pair<int, int>> direction= {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(freshFruits > 0 && !q.empty()) 
        {
            int qSize = q.size();
            for (int k = 0; k< qSize; k++) {
                // fetch from queue
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto& dir : direction) {
                    int newI = i+dir.first;
                    int newJ = j+dir.second;

                    if(newI >=0 && newI < grid.size() && newJ >=0 &&
                            newJ < grid[0].size() && grid[newI][newJ] == 1){
                                grid[newI][newJ] = 2;
                                q.push({newI, newJ});
                                // for each fruit which is fresh make it bad
                                freshFruits--;
                            }
                }
            }
            timer++;
        }
        if(freshFruits == 0) return timer;
        return -1;
    }
};
