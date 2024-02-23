class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n); // {destination, price}
        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].push_back({to, price});
        }
        
        // Using Dijkstra's algorithm
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {cost, city, stops}
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cost = top[0];
            int city = top[1];
            int stops = top[2];
            
            if (city == dst)
                return cost;
            
            if (stops > k)
                continue;
            
            for (const auto& neighbor : graph[city]) {
                int nextCity = neighbor.first;
                int priceToNextCity = neighbor.second;
                pq.push({cost + priceToNextCity, nextCity, stops + 1});
            }
        }
        
        return -1; // No such route found
        
    }
};
