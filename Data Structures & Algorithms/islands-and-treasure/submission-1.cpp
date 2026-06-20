class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        // Apply BFS like a ripple flood effect from all the source together
        // Go to water and drop stone and apply BFS. 
        // we will keep on writing the distance once we reach the land

        // Gather all the water in one queue. So that we can traverse together
        queue<pair<int,int>> q;
        for(int i =0; i< grid.size(); i++) {
            for(int j =0; j< grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        // create 4 direction for browsing.
        vector<pair<int, int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        /// BFS Radiant process now
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // no need of visited since we are changing
            // the grid itseld with distance

            for(auto& dir: direction) {
                int newR = r + dir.first;
                int newC = c + dir.second;

                // check bound and cell is unvisited
                if(newR >=0 && newR < grid.size() && newC >=0 && newC < grid[0].size() && grid[newR][newC] == 2147483647) {
                    grid[newR][newC] = grid[r][c] + 1;
                    q.push({newR, newC});
                }
            }
        }

        /*
        Highly Inefficient DFS
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i =0; i < grid.size(); i++) {
            for(int j = 0; j< grid[0].size(); j++) {
                if(grid[i][j] == 2147483647) {
                    // find min distance from waterbody
                    grid[i][j] = dfs(i, j, grid, visited);
                }
            }
        }*/


        
    }

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 1e6;
        }
        if(visited[i][j] == 1) {
            return 1e6;
        }        

       if(grid[i][j] == -1) {
            return 1e6;
        }


        //reached waterbody
        if(grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = 1;
        int res = 1e6;
        res = min(res, dfs(i+1,j,grid, visited));
        res = min(res, dfs(i-1,j,grid, visited));
        res = min(res, dfs(i,j+1,grid, visited));
        res = min(res, dfs(i,j-1,grid, visited));

        visited[i][j] = 0;

        return (res >=1e6)? 1e6 : 1+res;
    }

    /*
    ======== RADIANT DFS Solution ============
    class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return;
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // IMPORTANT: Start DFS from the TREASURE (0) 
                // It is much more efficient to spread out from the 0s
                // than to search for a 0 from every INF.
                if (grid[i][j] == 0) {
                    dfs(i, j, grid, 0);
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int dist) {
        // 1. Boundary check
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        // 2. Obstacle check
        if (grid[i][j] == -1) {
            return;
        }

        // 3. Distance Check (The most important part)
        // If the current distance we've traveled is GREATER than 
        // a distance already recorded in this cell, stop this path.
        // This also prevents infinite loops, so we don't need a "visited" matrix.
        if (dist > grid[i][j] && dist != 0) {
            return;
        }
        
        // 4. Update the cell with the shorter distance
        grid[i][j] = dist;

        // 5. Explore neighbors with dist + 1
        dfs(i + 1, j, grid, dist + 1);
        dfs(i - 1, j, grid, dist + 1);
        dfs(i, j + 1, grid, dist + 1);
        dfs(i, j - 1, grid, dist + 1);
    }
};
    */
};
