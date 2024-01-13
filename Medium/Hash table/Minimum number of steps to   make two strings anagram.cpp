class Solution {
public:
    int minSteps(string s, string t) {
        if (s.length() != t.length()) {
            return -1; // Invalid input, handle accordingly
        }

        // Create two unordered maps to store character counts for s and t
        unordered_map<char, int> countS, countT;

        // Count characters in string s
        for (char c : s) {
            countS[c]++;
        }

        // Count characters in string t
        for (char c : t) {
            countT[c]++;
        }

        // Calculate the minimum steps needed to make t an anagram of s
        int steps = 0;
        for (const auto& pair : countS) {
            char c = pair.first;
            int countInS = pair.second;
            int countInT = countT[c];

            // If character exists in t but with fewer occurrences, update steps
            if (countInS > countInT) {
                steps += (countInS - countInT);
            }
        }

        return steps;
        
    }
};
