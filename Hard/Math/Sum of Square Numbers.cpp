class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a) {
            long b = c - a * a;
            double sqrt_b = sqrt(b);
            if (sqrt_b == (int)sqrt_b) {
                return true;
            }
        }
        return false;
        
    }
};
