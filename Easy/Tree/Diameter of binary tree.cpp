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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDepth(root, diameter);
        return diameter;
    }

private:
    int calculateDepth(TreeNode* root, int& diameter) {
        if (root == nullptr) return 0;
        
        // Calculate the depth of left and right subtrees
        int leftDepth = calculateDepth(root->left, diameter);
        int rightDepth = calculateDepth(root->right, diameter);
        
        // Update diameter if the sum of left and right depths is greater
        diameter = std::max(diameter, leftDepth + rightDepth);
        
        // Return the depth of the current node's subtree
        return 1 + std::max(leftDepth, rightDepth);
        
    }
};
