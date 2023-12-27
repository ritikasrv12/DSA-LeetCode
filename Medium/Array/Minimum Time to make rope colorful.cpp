class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();

        // dp[i][j] represents the minimum time to make the first i balloons colorful
        // where the last balloon is of color j
        vector<vector<int>> dp(n + 1, vector<int>(26, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                // Initialize dp[i][j] with the previous minimum cost
                dp[i][j] = dp[i - 1][j];
            }

            // Find the previous balloon with the same color as the current one
            int prevSameColor = -1;
            for (int k = i - 2; k >= 0; --k) {
                if (colors[k] == colors[i - 1]) {
                    prevSameColor = k;
                    break;
                }
            }

            for (int j = 0; j < 26; ++j) {
                // Update the minimum cost for the current balloon
                if (j != colors[i - 1] - 'a') {
                    dp[i][colors[i - 1] - 'a'] = max(dp[i][colors[i - 1] - 'a'], neededTime[i - 1] + dp[i - 1][j]);
                } else if (prevSameColor != -1) {
                    dp[i][j] = max(dp[i][j], neededTime[i - 1] + dp[prevSameColor][j]);
                }
            }
        }

        // Find the maximum time in the last row
        int result = 0;
        for (int j = 0; j < 26; ++j) {
            result = max(result, dp[n][j]);
        }

        return result;
        
    }
};
