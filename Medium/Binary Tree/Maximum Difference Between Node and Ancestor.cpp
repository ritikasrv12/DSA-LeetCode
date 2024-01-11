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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) {
            return maxVal - minVal;
        }

        // Update min and max values along the path
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        // Recursively visit left and right subtrees
        int leftDiff = dfs(node->left, minVal, maxVal);
        int rightDiff = dfs(node->right, minVal, maxVal);

        // Return the maximum difference between ancestors and descendants
        return max(leftDiff, rightDiff);
        
    }
};
