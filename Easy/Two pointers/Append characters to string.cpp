class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size(), n = t.size();
        int j = 0; // Pointer for string t
        
        for (int i = 0; i < m && j < n; ++i) {
            if (s[i] == t[j]) {
                ++j; // Move pointer of t if there's a match
            }
        }
        
        // Characters left in t that need to be appended
        return n - j;

        
    }
};
