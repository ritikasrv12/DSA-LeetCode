#include <vector>
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        combineHelper(n, k, 1, currentCombination, result);
        return result;
    }
    
private:
    void combineHelper(int n, int k, int start, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (currentCombination.size() == k) {
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            currentCombination.push_back(i);
            combineHelper(n, k, i + 1, currentCombination, result);
            currentCombination.pop_back();
        }
        
    }
};
