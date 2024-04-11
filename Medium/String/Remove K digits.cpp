class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        // Iterate through each digit in num
        for (char digit : num) {
            // While the stack is not empty, the current digit is less than the top of the stack,
            // and there are still digits to be removed (k > 0), pop elements from the stack.
            while (!st.empty() && k > 0 && digit < st.top()) {
                st.pop();
                k--;
            }
            // Push the current digit onto the stack
            st.push(digit);
        }
        
        // If there are still digits to be removed (k > 0), remove them from the end of the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Construct the resulting string from the stack elements
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        // Remove leading zeroes
        int i = 0;
        while (i < result.length() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);
        
        // If result is empty, return "0", otherwise return result
        return result.empty() ? "0" : result;
        
    }
};
