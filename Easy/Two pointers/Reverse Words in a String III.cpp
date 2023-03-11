class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        while (i < n) {
            // Skip whitespace
            while (i < n && s[i] == ' ') {
                i++;
            }
            // Find the end of the current word
            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }
            // Reverse the current word
            int left = i;
            int right = j - 1;
            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            // Move to the next word
            i = j;
        }
        return s;

        
    }
};
