class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create an adjacency list representation of the graph
        std::vector<std::unordered_set<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]); // Considering bidirectional edges
        }
        
        // Initialize a visited set to keep track of visited vertices
        std::vector<bool> visited(n, false);
        
        // Call DFS to check if there's a valid path from source to destination
        return dfs(adjList, visited, source, destination);
    }
    
private:
    bool dfs(const std::vector<std::unordered_set<int>>& adjList, std::vector<bool>& visited, int current, int destination) {
        // If we reach the destination vertex, return true
        if (current == destination) {
            return true;
        }
        
        // Mark the current vertex as visited
        visited[current] = true;
        
        // Traverse all neighbors of the current vertex
        for (int neighbor : adjList[current]) {
            // If the neighbor is not visited, recursively check if there's a path from it to the destination
            if (!visited[neighbor]) {
                if (dfs(adjList, visited, neighbor, destination)) {
                    return true; // If a path is found, return true
                }
            }
        }
        
        // If no path is found from the current vertex to the destination, return false
        return false;
        
    }
};
