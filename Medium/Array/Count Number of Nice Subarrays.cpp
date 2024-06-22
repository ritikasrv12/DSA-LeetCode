class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCounts;
        prefixCounts[0] = 1; // Initialize with 0 prefix sum
        int count = 0, prefixSum = 0;

        for (int num : nums) {
            // Increment prefixSum if the number is odd
            prefixSum += num % 2;
            
            // If (prefixSum - k) exists in the map, it means there are subarrays with exactly k odd numbers
            if (prefixCounts.find(prefixSum - k) != prefixCounts.end()) {
                count += prefixCounts[prefixSum - k];
            }
            
            // Update the prefix sum count
            prefixCounts[prefixSum]++;
        }

        return count;
        
    }
};
