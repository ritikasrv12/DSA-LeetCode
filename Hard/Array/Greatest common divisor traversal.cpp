class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        
        // Construct the graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (gcd(nums[i], nums[j]) > 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        // Perform DFS to check if all nodes are reachable from each other
        unordered_set<int> visited;
        dfs(0, graph, visited);
        
        // If all nodes are visited, return true
        return visited.size() == n;
    }
    
private:
    void dfs(int node, vector<vector<int>>& graph, unordered_set<int>& visited) {
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, graph, visited);
            }
        }
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
        
    }
};
