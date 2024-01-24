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
    int pseudoPalindromicPaths (TreeNode* root) {
        return countPaths(root, vector<int>(10, 0));
    }

private:
    int countPaths(TreeNode* node, vector<int> freq) {
        if (!node)
            return 0;

        freq[node->val]++;

        // If it's a leaf node, check if the path is pseudo-palindromic
        if (!node->left && !node->right) {
            return isPseudoPalindromic(freq) ? 1 : 0;
        }

        int leftPaths = countPaths(node->left, freq);
        int rightPaths = countPaths(node->right, freq);

        freq[node->val]--; // Backtrack

        return leftPaths + rightPaths;
    }

    bool isPseudoPalindromic(vector<int>& freq) {
        int oddCount = 0;

        for (int f : freq) {
            if (f % 2 != 0) {
                oddCount++;
                if (oddCount > 1)
                    return false;
            }
        }

        return true;
        
    }
};
