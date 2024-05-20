class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalXORSum = 0;

        // Iterate through all possible subsets (2^n subsets)
        for (int subset = 0; subset < (1 << n); ++subset) {
            int subsetXOR = 0;
            for (int i = 0; i < n; ++i) {
                // Check if the ith element is in the current subset
                if (subset & (1 << i)) {
                    subsetXOR ^= nums[i];
                }
            }
            totalXORSum += subsetXOR;
        }
        
        return totalXORSum;
        
    }
};
