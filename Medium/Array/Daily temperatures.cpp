class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);  // Initialize the result array with zeros.
        stack<int> st;  // Stack to keep track of indices.

        for (int i = 0; i < n; ++i) {
            // Check if the current temperature is greater than the temperature at the top of the stack.
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                answer[prevIndex] = i - prevIndex;  // Calculate the number of days to wait.
            }

            st.push(i);  // Push the current index onto the stack.
        }

        return answer;
        
    }
};
