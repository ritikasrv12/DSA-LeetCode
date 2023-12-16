class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the lengths are different, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Use a hash map to count the occurrences of each character in both strings
        unordered_map<char, int> charCount;

        // Count characters in string s
        for (char c : s) {
            charCount[c]++;
        }

        // Decrement the count for characters in string t
        for (char c : t) {
            charCount[c]--;

            // If a character count becomes negative, strings are not anagrams
            if (charCount[c] < 0) {
                return false;
            }
        }

        // Check if all character counts are zero
        for (const auto& entry : charCount) {
            if (entry.second != 0) {
                return false;
            }
        }

        // If all checks pass, strings are anagrams
        return true;
        
    }
};
