class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        
        // If the array has 4 or fewer elements, we can make all elements the same
        if (n <= 4) {
            return 0;
        }
        
        // Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Initialize the minimum difference to a large value
        int minDiff = INT_MAX;
        
        // Check the 4 possible cases
        minDiff = std::min(minDiff, nums[n-1] - nums[3]);
        minDiff = std::min(minDiff, nums[n-2] - nums[2]);
        minDiff = std::min(minDiff, nums[n-3] - nums[1]);
        minDiff = std::min(minDiff, nums[n-4] - nums[0]);
        
        return minDiff;
    }
};
