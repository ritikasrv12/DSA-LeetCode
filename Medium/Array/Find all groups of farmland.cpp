class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int m = land.size();
        int n = land[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    int r2 = i, c2 = j;
                    
                    // Find bottom right corner of the group
                    while (r2 + 1 < m && land[r2 + 1][j] == 1) ++r2;
                    while (c2 + 1 < n && land[i][c2 + 1] == 1) ++c2;
                    
                    // Add group coordinates to the result
                    result.push_back({i, j, r2, c2});
                    
                    // Mark this group as visited
                    for (int r = i; r <= r2; ++r) {
                        for (int c = j; c <= c2; ++c) {
                            land[r][c] = 0;
                        }
                    }
                }
            }
        }
        
        return result;

        
    }
};
