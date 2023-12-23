class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited; // To store visited points
        int x = 0, y = 0; // Current coordinates

        // Add the starting point to the set
        visited.insert(to_string(x) + "," + to_string(y));

        // Traverse the path
        for (char direction : path) {
            // Update coordinates based on the direction
            if (direction == 'N') y++;
            else if (direction == 'S') y--;
            else if (direction == 'E') x++;
            else if (direction == 'W') x--;

            // Check if the current point has been visited before
            string currentPoint = to_string(x) + "," + to_string(y);
            if (visited.count(currentPoint) > 0) {
                return true; // Path crosses itself
            }

            // Add the current point to the set
            visited.insert(currentPoint);
        }

        return false; // Path does not cross itself
        
    }
};
