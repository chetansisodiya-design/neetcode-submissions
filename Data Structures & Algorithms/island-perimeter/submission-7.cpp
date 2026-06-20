class Solution {
public:
    // solution traverse the matrix using dfs and keep 
    // if we reaching out of bound or on water body means we 
    // we crossed one perimeter. So add 1 to perimiter
    int islandPerimeter2(vector<vector<int>>& grid) {
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
        // Condition A: Out of bounds is a perimeter edge
        if(i <0 || i >= grid.size() || j < 0 || j >= grid[0].size() ) {
            count++;
            return;
        }
        // Condition B: Water is a perimeter edge
        if(grid[i][j] == 0) {
            count++;
            return;
        }
// Condition C: Already visited land is NOT a perimeter edge        
        if(visited[i][j] == 1) {
            return;
        }
        if(grid[i][j] != 0) {
            // Mark current land as visited            
            visited[i][j] = 1;
            DFS(i+1, j,grid,visited, count);
            DFS(i-1, j,grid,visited, count);
            DFS(i, j+1,grid,visited, count);
            DFS(i, j-1,grid,visited, count);
        }
    }
int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < row; i++) {
            // Fixed: changed i < col to j < col
            for (int j = 0; j < col; j++) { 
                if (grid[i][j] == 1) {
                    // Start BFS from the first piece of land found
                    queue<pair<int, int>> q;
                    int perimeter = 0;

                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto& dir : direction) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;

                            // If neighbor is out of bounds or water, it's a perimeter edge
                            if (nx < 0 || ny < 0 || nx >= row || ny >= col || grid[nx][ny] == 0) {
                                perimeter++;
                            } 
                            // Fixed: Changed 'else if {' to just 'else {'
                            else {
                                // If it's land and not visited, add to queue
                                if (visited[nx][ny] == 0) {
                                    visited[nx][ny] = 1;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                    // Since there is only one island, we return once BFS is done
                    return perimeter;
                }
            }
        }
        return 0;
    }
};