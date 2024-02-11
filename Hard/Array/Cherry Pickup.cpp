class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Create a 3D dp array to store the maximum cherries collected
        // dp[i][j][k] represents the maximum cherries collected starting from row i,
        // with robot 1 at column j and robot 2 at column k
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        return dfs(grid, dp, 0, 0, cols - 1);
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int col1, int col2) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If the current row exceeds the grid, return 0
        if (row == rows)
            return 0;
        
        // If the result for this state is already calculated, return it
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        
        // Calculate cherries collected by both robots at current row
        int cherries = grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);
        
        // Calculate maximum cherries collected by both robots at next row
        int maxCherries = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newCol1 = col1 + i;
                int newCol2 = col2 + j;
                
                // Check if new positions are valid
                if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols) {
                    maxCherries = max(maxCherries, dfs(grid, dp, row + 1, newCol1, newCol2));
                }
            }
        }
        
        // Update dp array with the result and return
        return dp[row][col1][col2] = cherries + maxCherries;
        
    }
};
