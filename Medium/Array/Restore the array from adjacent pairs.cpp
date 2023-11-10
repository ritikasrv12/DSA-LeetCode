class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacency;
        unordered_set<int> visited;

        // Build adjacency map
        for (const auto& pair : adjacentPairs) {
            adjacency[pair[0]].push_back(pair[1]);
            adjacency[pair[1]].push_back(pair[0]);
        }

        // Start from any element in the adjacency map
        int start = adjacency.begin()->first;
        vector<int> result;

        dfs(start, adjacency, visited, result);

        return result;
    }

private:
    void dfs(int current, unordered_map<int, vector<int>>& adjacency, unordered_set<int>& visited, vector<int>& result) {
        visited.insert(current);
        result.push_back(current);

        for (int neighbor : adjacency[current]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adjacency, visited, result);
            }
        }
        
    }
};
