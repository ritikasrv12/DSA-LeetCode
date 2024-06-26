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
void inorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }
    
    // Function to construct a balanced BST from a sorted list of values
    TreeNode* sortedListToBST(vector<int>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = sortedListToBST(nodes, start, mid - 1);
        node->right = sortedListToBST(nodes, mid + 1, end);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
         vector<int> nodes;
        inorderTraversal(root, nodes);
        return sortedListToBST(nodes, 0, nodes.size() - 1);
        
    }
};
