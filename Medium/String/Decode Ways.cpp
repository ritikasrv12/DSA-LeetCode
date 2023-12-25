class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        // Base cases
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        
        if (n == 1) {
            return 1;
        }
        
        // dp[i] represents the number of ways to decode the string up to index i
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0;
        
        for (int i = 2; i <= n; ++i) {
            // Check if single digit is valid
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            // Check if two digits is valid
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
        
    }
};
