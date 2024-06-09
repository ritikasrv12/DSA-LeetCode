class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> remainderCount;
        // Initialize with the remainder 0 seen once (to handle the case when a prefix itself is divisible by k)
        remainderCount[0] = 1;
        
        int count = 0;       // To store the number of valid subarrays
        int prefixSum = 0;   // To store the prefix sum
        
        // Iterate through the array
        for (int num : nums) {
            prefixSum += num;  // Update the prefix sum
            
            // Get the remainder of the prefix sum when divided by k
            int remainder = prefixSum % k;
            
            // If remainder is negative, convert it to a positive equivalent
            if (remainder < 0) {
                remainder += k;
            }
            
            // If this remainder has been seen before, it means there are 'remainderCount[remainder]' subarrays
            // ending at the current index which are divisible by k
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }
            
            // Increment the count of this remainder in the hash map
            remainderCount[remainder]++;
        }
        
        return count;  // Return the total count of subarrays divisible by k
    }
};
