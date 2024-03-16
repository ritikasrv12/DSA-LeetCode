class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxLen = 0, count = 0;
        
        // Initialize map with initial sum 0 at index -1
        mp[0] = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 1) ? 1 : -1;
            
            // If the same sum has been seen before, calculate the length of subarray
            if (mp.find(count) != mp.end()) {
                maxLen = max(maxLen, i - mp[count]);
            } else {
                // Otherwise, store the current sum with its index
                mp[count] = i;
            }
        }
        
        return maxLen;
        
    }
};
