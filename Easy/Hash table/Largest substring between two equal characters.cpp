class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLength = -1;
        unordered_map<char, int> firstOccurrence;

        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s[i];

            // Check if the character has occurred before
            if (firstOccurrence.find(currentChar) == firstOccurrence.end()) {
                // If not, record its first occurrence
                firstOccurrence[currentChar] = i;
            } else {
                // If yes, calculate the length of the substring and update maxLength
                int currentLength = i - firstOccurrence[currentChar] - 1;
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
