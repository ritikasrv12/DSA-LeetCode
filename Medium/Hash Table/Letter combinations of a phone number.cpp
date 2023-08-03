#include <vector>
#include <string>
using namespace std;
class Solution {
    private:
    vector<string> result;
    vector<string> mapping = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void backtrack(string& current, const string& digits, int index) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '2'; // Convert digit to an index for mapping
        
        for (char letter : mapping[digit]) {
            current.push_back(letter);
            backtrack(current, digits, index + 1);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return result;
        
        string current;
        backtrack(current, digits, 0);
        return result;
        
    }
};
