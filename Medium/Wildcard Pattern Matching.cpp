class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
         int n = pattern.size();
        int m = str.size();
        
        // Create a DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Base case: both pattern and str are empty
        dp[0][0] = true;
        
        // Fill the first row (when str is empty)
        for (int i = 1; i <= n; i++) {
            if (pattern[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        
        // The result is in the bottom-right cell of the DP table
        return dp[n][m] ? 1 : 0;
        // code here
    }
};
