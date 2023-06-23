class Solution {
public:
    int longestArithSeqLength(std::vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        std::unordered_map<int, std::unordered_map<int, int>> dp;

        for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            int diff = nums[i] - nums[j];
            
            dp[i][diff] = dp[j][diff] + 1;
            
            // Update the maxLength
            maxLength = std::max(maxLength, dp[i][diff]);
        }
    }
    
    // Return the maxLength + 1 (including the current element)
    return maxLength + 1;
}

int main() {
    std::vector<int> nums = {3, 6, 9, 12};
    int result = longestArithSeqLength(nums);
    std::cout << "Length of the longest arithmetic subsequence: " << result << std::endl;
    
    return 0;

    }
};
