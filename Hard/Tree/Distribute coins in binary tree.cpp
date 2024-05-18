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
int moves;

    int postOrderTraversal(TreeNode* node) {
        if (!node) return 0;

        int leftExcess = postOrderTraversal(node->left);
        int rightExcess = postOrderTraversal(node->right);

        // Total moves needed from left and right subtrees
        moves += abs(leftExcess) + abs(rightExcess);

        // Current node's excess coins
        return node->val + leftExcess + rightExcess - 1;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        postOrderTraversal(root);
        return moves;
        
    }
};
