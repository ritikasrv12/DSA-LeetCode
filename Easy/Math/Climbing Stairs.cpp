class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Initialize a vector to store the number of ways for each step
        std::vector<int> dp(n + 1, 0);

        // Base cases
        dp[1] = 1;
        dp[2] = 2;

        // Build the table
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the number of ways to reach the top step
        return dp[n];
        
    }
};
