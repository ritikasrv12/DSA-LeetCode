class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        // Track indices of opening parentheses
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    // If there is no matching opening parenthesis, mark this closing parenthesis for removal
                    s[i] = '*';
                }
            }
        }
        
        // Mark remaining unmatched opening parentheses for removal
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        // Remove marked characters from the string
        string result = "";
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }
        
        return result;
        
    }
};
