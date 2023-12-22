class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int zerosLeft = 0;
        int onesRight = std::count(s.begin(), s.end(), '1');

        // Iterate through the string, considering each position as a split point
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                zerosLeft++;
            } else {
                onesRight--;
            }

            // Update the maximum score
            maxScore = std::max(maxScore, zerosLeft + onesRight);
        }

        return maxScore;
        
    }
};
