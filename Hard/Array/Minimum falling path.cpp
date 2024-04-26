class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        // Initialize a dp array to store the minimum sum falling path
        vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));
        
        // Initialize the dp array with the values of the first row
        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }
        
        // Iterate through the grid row by row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Compute the minimum sum for the current cell
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][k]);
                    }
                }
            }
        }
        
        // Find the minimum sum in the last row
        int minSum = numeric_limits<int>::max();
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[n - 1][j]);
        }
        
        return minSum;
        
    }
};
