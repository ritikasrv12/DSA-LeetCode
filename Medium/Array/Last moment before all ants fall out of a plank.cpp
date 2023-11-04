class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTime = 0;
        
        // Calculate the time for ants moving to the left.
        for (int position : left) {
            maxTime = max(maxTime, position);
        }
        
        // Calculate the time for ants moving to the right.
        for (int position : right) {
            maxTime = max(maxTime, n - position);
        }
        
        return maxTime;
        
    }
};
