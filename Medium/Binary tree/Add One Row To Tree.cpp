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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        // Recursively traverse the tree to reach the depth
        addRow(root, val, depth, 1);
        return root;
    }
    
private:
    void addRow(TreeNode* node, int val, int depth, int currentDepth) {
        if (!node) return;
        if (currentDepth == depth - 1) {
            // Insert new nodes at the desired depth
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = node->left;
            node->left = newLeft;
            
            TreeNode* newRight = new TreeNode(val);
            newRight->right = node->right;
            node->right = newRight;
            return;
        }
        // Recursively traverse left and right subtrees
        addRow(node->left, val, depth, currentDepth + 1);
        addRow(node->right, val, depth, currentDepth + 1);
        
    }
};
