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
    bool evaluateTree(TreeNode* root) {
        if (!root) return false; // Base case: empty tree
        
        // If leaf node, return its boolean value
        if (!root->left && !root->right) {
            return root->val;
        }
        
        // Recursively evaluate left and right children
        bool left_val = evaluateTree(root->left);
        bool right_val = evaluateTree(root->right);
        
        // Apply boolean operation based on the node's value
        if (root->val == 2) { // OR operation
            return left_val || right_val;
        } else { // AND operation
            return left_val && right_val;
        }
        
    }
};
