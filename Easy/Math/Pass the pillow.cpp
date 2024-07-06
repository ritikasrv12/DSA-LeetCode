class Solution {
public:
    int passThePillow(int n, int time) {
        int effectiveTime = time % (2 * (n - 1));

        // Determine the direction and position of the pillow
        if (effectiveTime <= n - 1) {
            // Moving forward
            return 1 + effectiveTime;
        } else {
            // Moving backward
            return n - (effectiveTime - (n - 1));
        }
        
    }
};
