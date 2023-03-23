class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // check if there are enough cables
        
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i; // initialize each node as a separate component
        
        int components = n; // start with n components (each node is a component)
        for (auto& c : connections) {
            int p1 = find(parent, c[0]);
            int p2 = find(parent, c[1]);
            if (p1 != p2) {
                parent[p1] = p2; // connect the two components
                components--; // decrease the number of components
            }
        }
        
        return components - 1; // the number of operations needed is equal to the number of components minus 1
    }
    
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) parent[i] = find(parent, parent[i]); // path compression
        return parent[i];
        
    }
};
