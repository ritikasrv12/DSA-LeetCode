class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        vector<string> validSubsequences;
        
        backtrack(arr, "", 0, maxLength);
        
        return maxLength;
    }
    
private:
    void backtrack(const vector<string>& arr, string current, int index, int& maxLength) {
        // Check if the current subsequence has unique characters
        if (hasUniqueCharacters(current)) {
            // Update the maximum length if the current subsequence is longer
            maxLength = max(maxLength, static_cast<int>(current.size()));
        } else {
            // If not unique, skip this subsequence
            return;
        }
        
        // Explore all possible subsequences
        for (int i = index; i < arr.size(); ++i) {
            // Include the current string in the subsequence
            backtrack(arr, current + arr[i], i + 1, maxLength);
        }
    }
    
    bool hasUniqueCharacters(const string& s) {
        // Check if a string has unique characters
        unordered_set<char> charSet;
        for (char c : s) {
            if (charSet.count(c) > 0) {
                return false; // Not unique
            }
            charSet.insert(c);
        }
        return true; // Unique
        
    }
};
