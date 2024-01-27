class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Base case
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp array using the recurrence relation
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int l = 0; l <= min(j, i - 1); l++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
                }
            }
        }

        return dp[n][k];
        
    }
};
