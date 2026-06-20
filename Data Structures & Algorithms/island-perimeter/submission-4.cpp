class Solution {
public:
    // perimeter  number of box*2 + 2
    // 1 box = 1*2+2 = 4
    // 8 box = 8*2+2 = 18
    // solution traverse the matri using dfs and keep 
    // and count the valid island.
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int islandCount = 0;      
        int firstX = 0; int firstY = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    firstX = i; firstY = j;
                    break;
                }
            }
        }
        //cout << "chetan " << i << " ," << j;
        DFS(firstX, firstY, grid, visited, islandCount);


        cout << "chetan: "<<  islandCount;
        return islandCount;
    }

    void DFS(int i , int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int& count) {

        if(i <0 || i >= grid.size() || j < 0 || j >= grid[0].size() ) {
            count++;
            return;
        }
        if(grid[i][j] == 0) {
            count++;
            return;
        }
        if(visited[i][j] == 1) {
            return;
        }

        if(grid[i][j] != 0) {
            visited[i][j] = 1;
            DFS(i+1, j,grid,visited, count);
            DFS(i-1, j,grid,visited, count);
            DFS(i, j+1,grid,visited, count);
            DFS(i, j-1,grid,visited, count);
        }

    }
    
};