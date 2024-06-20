class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // Sort the basket positions
        sort(position.begin(), position.end());
        
        // Helper function to check if we can place m balls with at least minDist apart
        auto canPlaceBalls = [&](int minDist) -> bool {
            int count = 1; // Place the first ball in the first basket
            int lastPosition = position[0]; // The position of the last placed ball

            for (int i = 1; i < position.size(); ++i) {
                if (position[i] - lastPosition >= minDist) {
                    count++;
                    lastPosition = position[i];
                }
                if (count == m) {
                    return true;
                }
            }
            return false;
        };

        // Binary search for the maximum minimum distance
        int low = 1;
        int high = position.back() - position.front();
        int best = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return best;
        
    }
};
