class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (n == 1) return {0}; // Special case: only one node
        
        vector<unordered_set<int>> adj(n); // Adjacency list to store the graph
        vector<int> degree(n, 0); // Degree of each node
        
        // Build the adjacency list and calculate degrees
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> leaves; // Queue to store current leaf nodes
        
        // Add all leaf nodes to the queue
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }
        
        // Keep removing leaves until only MHT roots remain
        while (n > 2) {
            int num_leaves = leaves.size();
            n -= num_leaves;
            
            for (int i = 0; i < num_leaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                // Remove the leaf and its edge
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        // Remaining nodes in the queue are MHT roots
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;

    }
};
