class Solution {
public:
    string reverseParentheses(string s) {
         stack<char> stk;
        for (char c : s) {
            if (c == ')') {
                string temp;
                // Pop until the matching '('
                while (!stk.empty() && stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop(); // Remove the '('
                // Push the reversed string back to the stack
                for (char ch : temp) {
                    stk.push(ch);
                }
            } else {
                stk.push(c);
            }
        }
        
        // Collect the result from the stack
        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};
