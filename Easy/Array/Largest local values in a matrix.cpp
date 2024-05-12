class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0)); // Initialize the result matrix
        
        // Iterate over the grid to find the maximum value in each 3x3 submatrix
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int maxVal = grid[i][j];
                // Iterate over the 3x3 submatrix centered around (i, j)
                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        maxVal = max(maxVal, grid[x][y]);
                    }
                }
                maxLocal[i][j] = maxVal;
            }
        }
        
        return maxLocal;
        
    }
};
