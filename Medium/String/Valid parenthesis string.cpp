class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0, max_open = 0;
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open = std::max(0, min_open - 1);
                max_open--;
                if (max_open < 0) // more ')' than '(' and '*' combined
                    return false;
            } else { // '*'
                min_open = std::max(0, min_open - 1);
                max_open++;
            }
        }
        
        return min_open == 0;
        
    }
};
