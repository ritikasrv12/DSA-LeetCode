class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j] represents the number of ways to get a sum of j using i dice
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
        
        // Base case: there is one way to get a sum of 0 with 0 dice
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                // Calculate dp[i][j] by considering each face of the die
                for (int face = 1; face <= k; ++face) {
                    if (j - face >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                    }
                }
            }
        }
        
        return dp[n][target];
        
    }
};
