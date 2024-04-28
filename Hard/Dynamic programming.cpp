class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector<int> count(n, 1); // Count of nodes in subtree rooted at i
        vector<int> ans(n, 0);   // Answer for each node
        
        // Step 1: DFS to calculate the count and answer for each node
        dfs(0, -1, tree, count, ans);
        
        // Step 2: DFS to update answer for each node based on parent's answer
        dfs2(0, -1, tree, count, ans, n);
        
        return ans;
    }
    
private:
    // DFS to calculate count and answer for each node
    void dfs(int node, int parent, const vector<vector<int>>& tree, vector<int>& count, vector<int>& ans) {
        for (int child : tree[node]) {
            if (child != parent) {
                dfs(child, node, tree, count, ans);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    
    // DFS to update answer for each node based on parent's answer
    void dfs2(int node, int parent, const vector<vector<int>>& tree, const vector<int>& count, vector<int>& ans, int n) {
        for (int child : tree[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + n - count[child];
                dfs2(child, node, tree, count, ans, n);
            }
        }
        
    }
};
