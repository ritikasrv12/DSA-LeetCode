class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        int count1 = 0; // Count for the pattern '0101...'
        int count2 = 0; // Count for the pattern '1010...'
        
        for (int i = 0; i < n; ++i) {
            // Check if the character at the current index matches the expected pattern for even indices
            if (i % 2 == 0) {
                count1 += (s[i] == '1' ? 1 : 0);
                count2 += (s[i] == '0' ? 1 : 0);
            }
            // Check if the character at the current index matches the expected pattern for odd indices
            else {
                count1 += (s[i] == '0' ? 1 : 0);
                count2 += (s[i] == '1' ? 1 : 0);
            }
        }
        
        // Return the minimum count among both patterns
        return min(count1, count2);
        
    }
};
