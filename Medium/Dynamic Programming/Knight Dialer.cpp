class Solution {
public:
    int knightDialer(int n) {
         const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(10, vector<long long>(n, 0));

        // Initialize the base case for n = 1
        for (int i = 0; i < 10; ++i) {
            dp[i][0] = 1;
        }

        // Define the valid knight moves
        vector<vector<int>> moves = {
            {4, 6}, {6, 8}, {7, 9},
            {4, 8}, {3, 9, 0}, {}, 
            {1, 7, 0}, {2, 6}, {1, 3},
            {2, 4}
        };

        // Dynamic programming to calculate the number of ways for each digit and each step
        for (int step = 1; step < n; ++step) {
            for (int digit = 0; digit < 10; ++digit) {
                for (int nextDigit : moves[digit]) {
                    dp[digit][step] = (dp[digit][step] + dp[nextDigit][step - 1]) % MOD;
                }
            }
        }

        // Sum up the ways to reach each digit after n moves
        long long result = 0;
        for (int digit = 0; digit < 10; ++digit) {
            result = (result + dp[digit][n - 1]) % MOD;
        }

        return static_cast<int>(result);
        
    }
};
