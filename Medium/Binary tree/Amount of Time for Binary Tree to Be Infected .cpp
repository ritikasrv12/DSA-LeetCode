/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfsToCreateGraph(vector<vector<int>>& graph,TreeNode* root) {
        if(root==NULL) return;
        
        if(root->left!=NULL) {
            dfsToCreateGraph(graph,root->left);
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right!=NULL) {
            dfsToCreateGraph(graph,root->right);
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> graph(100001);
        dfsToCreateGraph(graph,root);
        
        vector<int> visit(100001,0);
        return dfs_for_defth(graph,visit,start);
    }
    
    int dfs_for_defth(vector<vector<int>>& graph,vector<int>& visit,int src) {
        visit[src]=1;
        int ans=0;
        for(int nbr : graph[src]) {
            if(visit[nbr]==0) {
                ans = max(ans,dfs_for_defth(graph,visit,nbr)+1);
            }
        }
        return ans;
        
          
    }
};
