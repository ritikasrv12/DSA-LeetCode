class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int minLeftover = INT_MAX;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int totalCost = prices[i] + prices[j];
                if (totalCost <= money) {
                    int leftover = money - totalCost;
                    minLeftover = std::min(minLeftover, leftover);
                }
            }
        }

        return (minLeftover == INT_MAX) ? money : minLeftover;
        
    }
};
