class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Traverse -> find island -> island not visited then visit it.

        int count = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));

        for(int i = 0; i< grid.size(); i++) {
            for(int j = 0; j< grid[0].size(); j++) {
                if(grid[i][j] == '1' && visited [i][j] == 0) {
                    //cout << "\n increment count";
                    count++;
                    // found island. Cover whole island by DFS
                    DFS(i, j, grid, visited);
                }
            }
        }
        return count;
    }
    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        // check base condition
        if(i< 0 || j < 0 || i>=grid.size() || j >= grid[0].size()) {
            return;
        }
        //Corner Case: Initially I was not returning on checking grid[i][j] == '0'
        // It caused issue since without this check and return - my DFS will traverse the
        // whole matrix and mark whole matrix as visited in 1 go.
        // So isolated island will also be marked as VIsited. They wont be popping up
        //in out loop where i am doing C++
        if(visited[i][j] == 1 || grid[i][j] == '0') {
            return;
        }
        //mark current node visited. Call DFS for its surrounding nodes
        visited[i][j] = 1;

        DFS(i+1, j, grid, visited);
        DFS(i-1, j, grid, visited);
        DFS(i, j+1, grid, visited);
        DFS(i, j-1, grid, visited);
    }
};
