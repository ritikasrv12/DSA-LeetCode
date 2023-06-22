class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = INT_MIN/2, sold = 0;
        for(int i=0; i<prices.size(); i++)
        {
            int p = prices[i];
            int hold2 = hold, sold2 = sold;
            hold = max(hold2,sold2-p);
            sold = max(sold2,hold2+p-fee);
        }
        return sold;
    }
};
