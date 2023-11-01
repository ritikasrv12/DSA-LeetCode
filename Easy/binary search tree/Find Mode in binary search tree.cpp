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
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        int current = 0; // Initialize the current element
        int count = 0; // Initialize the count of the current element
        int maxCount = 0; // Initialize the maximum count of any element
        inOrder(root, modes, current, count, maxCount);
        return modes;
    }
    
    void inOrder(TreeNode* node, vector<int>& modes, int& current, int& count, int& maxCount) {
        if (!node) return;
        
        // Traverse the left subtree
        inOrder(node->left, modes, current, count, maxCount);
        
        // Process the current node
        if (node->val == current) {
            count++;
        } else {
            count = 1;
            current = node->val;
        }
        
        if (count > maxCount) {
            // We found a new mode, clear the old ones
            modes.clear();
            modes.push_back(current);
            maxCount = count;
        } else if (count == maxCount) {
            // Add the current element to the list of modes
            modes.push_back(current);
        }
        
        // Traverse the right subtree
        inOrder(node->right, modes, current, count, maxCount);
        
    }
};
