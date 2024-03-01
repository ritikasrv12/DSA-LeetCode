class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        // Find the rightmost '1'
        int pos = s.find_last_of('1');
        // Move '1' to the last position
        swap(s[pos], s[n - 1]);
        return s;
        
    }
};
