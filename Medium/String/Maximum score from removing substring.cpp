class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Determine the order of removal based on the higher score
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        // Helper function to remove substrings and calculate score
        auto removeSubstring = [&](string& s, char a, char b, int score) {
            stack<char> st;
            int totalScore = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == a && c == b) {
                    st.pop();
                    totalScore += score;
                } else {
                    st.push(c);
                }
            }
            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return make_pair(remaining, totalScore);
        };

        // First pass: remove all "ab"
        auto result = removeSubstring(s, 'a', 'b', x);
        s = result.first;
        int totalScore = result.second;

        // Second pass: remove all "ba"
        result = removeSubstring(s, 'b', 'a', y);
        totalScore += result.second;

        return totalScore;
        
    }
};
