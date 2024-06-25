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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return root;
    }

private:
    void traverse(TreeNode* node, int& sum) {
        if (!node) return;
        // Traverse right subtree first
        traverse(node->right, sum);
        // Update the sum and node's value
        sum += node->val;
        node->val = sum;
        // Traverse left subtree
        traverse(node->left, sum);
        
    }
};
