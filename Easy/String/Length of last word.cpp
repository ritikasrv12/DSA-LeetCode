class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters until a space is encountered
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
        
    }
};
