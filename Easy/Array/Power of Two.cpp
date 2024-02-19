class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) // If n is non-positive, it can't be a power of two
            return false;
        
        // A power of two number has only one bit set in its binary representation
        // So, if we do a bitwise AND of n and n - 1, and the result is 0, then it's a power of two
        return (n & (n - 1)) == 0;
        
    }
};
