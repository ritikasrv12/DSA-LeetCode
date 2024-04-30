class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> count;
        count[0] = 1; // Start with an empty substring
        
        int mask = 0;
        long long wonderful = 0;
        
        for (char c : word) {
            int index = c - 'a';
            mask ^= 1 << index; // Toggle the bit corresponding to the character
            
            // Check for substrings with at most one odd count
            wonderful += count[mask];
            for (int i = 0; i < 10; ++i) {
                int check_mask = mask ^ (1 << i);
                wonderful += count[check_mask];
            }
            
            count[mask]++;
        }
        
        return wonderful;
        
    }
};
