class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles; // Start with the initial number of full bottles
        int emptyBottles = numBottles;
        
        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            totalDrank += newBottles;
            emptyBottles = emptyBottles % numExchange + newBottles;
        }
        
        return totalDrank;
        
    }
};
