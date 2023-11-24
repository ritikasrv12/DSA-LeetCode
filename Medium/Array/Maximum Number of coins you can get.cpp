class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size() / 3;
        int result = 0;
        
        for (int i = n; i < 3 * n; i += 2) {
            result += piles[i];
        }
        
        return result;
        
    }
};
