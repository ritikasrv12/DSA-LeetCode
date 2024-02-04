class Solution {
public:
    string minWindow(string s, string t) {
         // Initialize a frequency map for characters in t
        unordered_map<char, int> charFreqT;
        for (char c : t) {
            charFreqT[c]++;
        }

        int left = 0; // Left pointer of the window
        int minLen = INT_MAX; // Minimum window length
        int minLenStart = 0; // Start index of the minimum window
        int requiredChars = t.length(); // Count of characters to be included in the window

        // Iterate over the string using the right pointer
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // Update the frequency map for the current character
            if (charFreqT.find(currentChar) != charFreqT.end()) {
                charFreqT[currentChar]--;
                if (charFreqT[currentChar] >= 0) {
                    requiredChars--;
                }
            }

            // Check if all characters in t are included in the window
            while (requiredChars == 0) {
                // Update the minimum window information
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLenStart = left;
                }

                // Move the left pointer to shrink the window
                char leftChar = s[left];
                if (charFreqT.find(leftChar) != charFreqT.end()) {
                    charFreqT[leftChar]++;
                    if (charFreqT[leftChar] > 0) {
                        requiredChars++;
                    }
                }
                left++;
            }
        }

        // Return the minimum window substring or an empty string if not found
        return (minLen == INT_MAX) ? "" : s.substr(minLenStart, minLen);
        
    }
};
