class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        // Calculate the prefix sum and suffix sum arrays
        vector<int> prefixSum(n, 0);
        vector<int> suffixSum(n, 0);
        
        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
            suffixSum[n - i - 1] = suffixSum[n - i] + nums[n - i - 1];
        }
        
        // Calculate the result array
        vector<int> result(n, 0);
        
        for (int i = 0; i < n; ++i) {
            int leftSum = i * nums[i] - (i > 0 ? prefixSum[i - 1] : 0);
            int rightSum = (i < n - 1 ? suffixSum[i + 1] : 0) - (n - 1 - i) * nums[i];
            
            result[i] = leftSum + rightSum;
        }
        
        return result;
        
    }
};
