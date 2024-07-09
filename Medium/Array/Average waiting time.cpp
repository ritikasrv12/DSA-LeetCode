class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitingTime = 0;
        int currentTime = 0;
        
        for (const auto& customer : customers) {
            int arrival = customer[0];
            int timeToPrepare = customer[1];
            
            // If the chef is idle when the customer arrives, start immediately
            if (currentTime < arrival) {
                currentTime = arrival;
            }
            
            // Complete the order
            currentTime += timeToPrepare;
            
            // Calculate the waiting time for this customer
            int waitingTime = currentTime - arrival;
            totalWaitingTime += waitingTime;
        }
        
        // Calculate and return the average waiting time
        return (double)totalWaitingTime / customers.size();
    
        
    }
};
