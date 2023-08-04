class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp[i] will be true if the substring s[0...i-1] can be segmented
        // into space-separated words from the wordDict.
        vector<bool> dp(n + 1, false);
        dp[0] = true; // An empty string can always be formed.
        
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                // Check if s[j...i-1] exists in the wordDict and s[0...j-1] can be segmented.
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
        
    }
};
