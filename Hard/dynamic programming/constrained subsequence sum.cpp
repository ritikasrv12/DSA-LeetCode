class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int maxSum = nums[0];

        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i]; // Initialize dp[i] with the current element as the default choice.
            for (int j = max(0, i - k); j < i; ++j) {
                dp[i] = max(dp[i], nums[i] + max(dp[j], 0));
                // Calculate the maximum subsequence sum ending at index i
                // by considering the last "k" valid indices.
            }
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
        
    }
};
