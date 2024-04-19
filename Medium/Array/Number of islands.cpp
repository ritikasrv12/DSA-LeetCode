class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        
        // Iterate through the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++count; // Found a new island
                    dfs(grid, i, j, rows, cols); // Explore the island
                }
            }
        }
        return count;
    }
    
    // Depth-First Search to explore the island
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
        // Base cases for out of bounds or not land
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') {
            return;
        }
        
        // Mark current cell as visited
        grid[i][j] = '0';
        
        // Explore adjacent cells
        dfs(grid, i + 1, j, rows, cols); // Down
        dfs(grid, i - 1, j, rows, cols); // Up
        dfs(grid, i, j + 1, rows, cols); // Right
        dfs(grid, i, j - 1, rows, cols); // Left
        
    }
};
