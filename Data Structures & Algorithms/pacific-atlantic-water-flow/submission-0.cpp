class Solution {
public:
        int ROWS, COLS;
        bool pacific, atlantic;
        vector<pair<int, int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        // pecific - i< 0(j - 0 to n), i (0 to n) j<0
        // atlantic i>=n (j = 0 to n), j >= n (j = 0 to n)
        // Pecific i<0, j < 0
        // Atlantic i>=ROWS j>=COLS
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> res;
        for(int i =0; i< ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                pacific = false;
                atlantic = false;

                dfs(heights, i, j, INT_MAX);
                if(pacific && atlantic) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, int preVal) {
        if(r< 0 || c < 0) {
            pacific = true;
            return;
        }
        if(r >=ROWS || c >= COLS) {
            atlantic = true;
            return;
        }
        // If current cell is greater then prec cell then return
        // bcoz water wont flow from smaller to bigger cell
        if(heights[r][c] > preVal) {
            return;
        }
        
        // Loops direction and apply DFS
        int temp = heights[r][c];
        for(auto dir : direction) {
            // Make current cell INT_MAX so that same cell is not travesed again
            // in same path.
            // We need to reveer it back for backtarking
            
            heights[r][c]= INT_MAX;
            dfs(heights, r+dir.first, c+dir.second, temp);
            if(pacific && atlantic) {
                break;
            }
        }
        heights[r][c] = temp;
    }

};
