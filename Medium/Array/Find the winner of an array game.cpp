class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int currentWinner = max(arr[0], arr[1]);
        int consecutiveWins = 0;
        
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] > currentWinner) {
                currentWinner = arr[i];
                consecutiveWins = 1;
            } else {
                consecutiveWins++;
            }
            
            if (consecutiveWins == k) {
                return currentWinner;
            }
        }
        
        return currentWinner;
        
    }
};
