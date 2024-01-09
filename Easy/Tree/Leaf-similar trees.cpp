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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1, leafValues2;

        // Helper function to perform depth-first traversal and collect leaf values
        auto collectLeafValues = [](TreeNode* root, vector<int>& leafValues) {
            if (root == nullptr) {
                return;
            }

            stack<TreeNode*> s;
            s.push(root);

            while (!s.empty()) {
                TreeNode* current = s.top();
                s.pop();

                if (current->left == nullptr && current->right == nullptr) {
                    leafValues.push_back(current->val);
                }

                if (current->right != nullptr) {
                    s.push(current->right);
                }

                if (current->left != nullptr) {
                    s.push(current->left);
                }
            }
        };

        // Collect leaf values for both trees
        collectLeafValues(root1, leafValues1);
        collectLeafValues(root2, leafValues2);

        // Compare the leaf value sequences
        return leafValues1 == leafValues2;
        
    }
};
