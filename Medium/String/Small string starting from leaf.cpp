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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }

private:
    string dfs(TreeNode* node, string suffix) {
        if (node == nullptr) return "|"; // "|" is lexicographically greater than any character

        char ch = 'a' + node->val;
        suffix = ch + suffix;

        if (node->left == nullptr && node->right == nullptr) // Leaf node
            return suffix;

        string left_str = dfs(node->left, suffix);
        string right_str = dfs(node->right, suffix);

        return min(left_str, right_str);
        
    }
};
