class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort the points based on the end point of each balloon
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1; // Initialize the number of arrows to 1 (we need at least 1 arrow)
        int end = points[0][1]; // Initialize the end point to the end of the first balloon
        
        // Iterate through the balloons
        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the previous end point,
            // it means we need another arrow
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1]; // Update the end point
            }
        }
        
        return arrows;
        
    }
};
