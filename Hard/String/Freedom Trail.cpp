class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        
        // Create a map to store the index positions of each character in the ring
        unordered_map<char, vector<int>> charIndexMap;
        for (int i = 0; i < n; ++i) {
            charIndexMap[ring[i]].push_back(i);
        }
        
        // Create a memoization table to store the minimum steps for each (ringIndex, keyIndex) pair
        vector<vector<int>> memo(m, vector<int>(n, INT_MAX));
        
        // Start from the first character of the key
        return dp(ring, key, 0, 0, charIndexMap, memo) + m;
    }
    
    // Recursive dynamic programming function to find the minimum steps
    int dp(string& ring, string& key, int ringIndex, int keyIndex, unordered_map<char, vector<int>>& charIndexMap, vector<vector<int>>& memo) {
        if (keyIndex == key.size()) {
            return 0; // Base case: finished spelling the key
        }
        
        if (memo[keyIndex][ringIndex] != INT_MAX) {
            return memo[keyIndex][ringIndex]; // Return memoized value if available
        }
        
        char targetChar = key[keyIndex];
        int minSteps = INT_MAX;
        // Iterate through all possible positions of the target character in the ring
        for (int newRingIndex : charIndexMap[targetChar]) {
            // Calculate the steps required to move the ring to the new position
            int clockWiseSteps = (newRingIndex - ringIndex + ring.size()) % ring.size();
            int antiClockWiseSteps = (ringIndex - newRingIndex + ring.size()) % ring.size();
            // Calculate the minimum steps recursively
            int steps = min(clockWiseSteps, antiClockWiseSteps) + dp(ring, key, newRingIndex, keyIndex + 1, charIndexMap, memo);
            minSteps = min(minSteps, steps);
        }
        
        // Update memo table
        memo[keyIndex][ringIndex] = minSteps;
        
        return minSteps;
        
    }
};
