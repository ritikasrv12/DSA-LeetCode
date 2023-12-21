class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // Extract x-coordinates from points
        vector<int> xCoordinates;
        for (const auto& point : points) {
            xCoordinates.push_back(point[0]);
        }

        // Sort x-coordinates
        sort(xCoordinates.begin(), xCoordinates.end());

        // Find the maximum width
        int maxWidth = 0;
        for (int i = 1; i < xCoordinates.size(); ++i) {
            maxWidth = max(maxWidth, xCoordinates[i] - xCoordinates[i - 1]);
        }

        return maxWidth;
        
    }
};
