class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        
        for (char ch : s) {
            if (!stk.empty() && abs(stk.top() - ch) == 32) {
                // If the top of the stack and the current character form a pair,
                // remove the top of the stack.
                stk.pop();
            } else {
                // Otherwise, push the current character onto the stack.
                stk.push(ch);
            }
        }
        
        // Reconstruct the string from the stack.
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
        
    }
};
