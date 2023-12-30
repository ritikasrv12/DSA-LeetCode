class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> charCount;

        for (const string& word : words) {
            for (char ch : word) {
                charCount[ch]++;
            }
        }

        // Check if the count of each character is divisible by the total number of words
        int totalWords = words.size();
        for (const auto& entry : charCount) {
            if (entry.second % totalWords != 0) {
                return false;
            }
        }

        return true;
        
    }
};
