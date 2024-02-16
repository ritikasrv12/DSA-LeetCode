class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
        
        // Count the frequency of each integer
        for (int num : arr) {
            freqMap[num]++;
        }
        
        // Sort frequencies in ascending order
        vector<int> frequencies;
        for (const auto& entry : freqMap) {
            frequencies.push_back(entry.second);
        }
        sort(frequencies.begin(), frequencies.end());
        
        int uniqueIntegers = frequencies.size();
        for (int freq : frequencies) {
            if (k >= freq) {
                k -= freq;
                uniqueIntegers--;
            } else {
                break;
            }
        }
        
        return uniqueIntegers;
        
    }
};
