class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right && s[left] == s[right]) {
            char target = s[left];
            while (left <= right && s[left] == target) {
                left++;
            }
            while (left <= right && s[right] == target) {
                right--;
            }
        }

        return max(right - left + 1, 0);
        
    }
};
