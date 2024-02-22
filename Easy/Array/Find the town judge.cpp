class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         vector<int> trustCount(n + 1, 0); // Initialize trust count for each person
        
        for (const auto& pair : trust) {
            int a = pair[0];
            int b = pair[1];
            trustCount[a]--; // Person 'a' trusts someone, decrement trust count
            trustCount[b]++; // Person 'b' is trusted by someone, increment trust count
        }
        
        for (int i = 1; i <= n; ++i) {
            if (trustCount[i] == n - 1) // Check if a person is trusted by all others
                return i;
        }
        
        return -1; // No town judge found
        
    }
};
