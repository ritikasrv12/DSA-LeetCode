class Solution {
public:
int total;
    int sumNumbers(TreeNode* root) {
        total = 0;
        helper(root, 0);
        return total;
         }
    
    void helper(TreeNode* root, int sum) {
        if (root == nullptr) return;
        
        sum = sum * 10 + root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            total += sum;
            return;
        }
        
        helper(root->left, sum);
        helper(root->right, sum);
    }
};
