class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
        
        // Initialize the result array with size n
        vector<int> result(n, 1);
        
        // Calculate the product of prefixes
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            result[i] *= prefix;
            prefix *= nums[i];
        }
        
        // Calculate the product of suffixes and combine with the previously calculated prefix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
        
    }
};
