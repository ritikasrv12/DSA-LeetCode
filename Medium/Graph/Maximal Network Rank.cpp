#include <vector>
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        std::vector<std::unordered_set<int>> adjList(n); // Adjacency list for each city
        std::vector<int> cityRank(n, 0); // Store the rank for each city
        
        for (const auto& road : roads) {
            adjList[road[0]].insert(road[1]); // Add the road to the adjacency list
            adjList[road[1]].insert(road[0]);
            
            cityRank[road[0]]++; // Increment the rank for both cities
            cityRank[road[1]]++;
        }
        
        int maxRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = cityRank[i] + cityRank[j];
                
                if (adjList[i].count(j)) { // If there's a road between cities i and j
                    rank--; // Subtract one because the road is counted only once
                }
                
                maxRank = std::max(maxRank, rank);
            }
        }
        
        return maxRank;
        
    }
};
