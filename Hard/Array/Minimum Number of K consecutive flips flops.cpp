class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipCount = 0; // Number of flips performed
        int currentFlips = 0; // Current flip state (odd or even)
        
        vector<int> isFlipped(n, 0); // Auxiliary array to mark the flip boundaries
        
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                currentFlips ^= isFlipped[i - k]; // Update currentFlips based on the window's left boundary
            }
            
            if (currentFlips % 2 == nums[i]) { // Need to flip if current state (with flips) is 0
                if (i + k > n) {
                    return -1; // Not enough elements to flip
                }
                ++flipCount;
                currentFlips ^= 1; // Toggle the current flip state
                isFlipped[i] = 1; // Mark the flip boundary
            }
        }
        
        return flipCount;
        
    }
};
