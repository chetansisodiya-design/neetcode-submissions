class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int count = 0;
        int maxCount = 0;
        
        vector<vector<int>> visited(grid.size(), (vector<int>(grid[0].size(),0)));

        for(int i = 0 ; i< grid.size(); i++) {
            for(int j = 0; j< grid[0].size(); j++) {
                if(grid[i][j] == 1 && visited[i][j]==0) {
                    DFS(i, j, grid, visited, count);
                    maxCount = max(count, maxCount);
                    count = 0;
                }
            }
        }
        return maxCount;
    }
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int& count) {
        if(i< 0 || j < 0 || i >=grid.size() || j >= grid[0].size()) {
            return;
        }
        if(visited[i][j] == 1 || grid[i][j] == 0) {
            return;
        }
        
        visited[i][j] = 1;
        count++;
        DFS(i+1, j, grid, visited, count);
        DFS(i-1, j, grid, visited, count);
        DFS(i, j+1, grid, visited, count);
        DFS(i, j-1, grid, visited, count);
    }
};
