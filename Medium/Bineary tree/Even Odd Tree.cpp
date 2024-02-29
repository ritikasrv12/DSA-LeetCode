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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0; // Tracks the current level index

        while (!q.empty()) {
            int size = q.size();
            int prevVal = (level % 2 == 0) ? INT_MIN : INT_MAX; // Initialize with extreme values based on level parity

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Check the value based on level parity
                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prevVal)) ||
                    (level % 2 != 0 && (node->val % 2 != 0 || node->val >= prevVal))) {
                    return false;
                }

                prevVal = node->val;

                // Enqueue children if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level++; // Move to the next level
        }

        return true;
        
    }
};
