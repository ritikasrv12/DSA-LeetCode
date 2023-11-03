class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int current = 1; // Initialize the current integer to 1 (the first integer in the range).

        for (int i = 0; i < target.size(); i++) {
            while (current != target[i]) {
                // Push and Pop operations until the current integer matches the target.
                result.push_back("Push");
                result.push_back("Pop");
                current++; // Increment the current integer.
            }
            // If the current integer matches the target, simply push it.
            result.push_back("Push");
            current++;
        }
        
        return result;
        
    }
};
