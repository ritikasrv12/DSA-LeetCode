class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        return true;

        TreeNode* root1 = root->left;
        TreeNode* root2 = root->right;
        return _isSymmetric(root1,root2);
        
    }
    bool _isSymmetric(TreeNode* root1,TreeNode* root2){
        if(root1 == root2)
        return true;
        else
        {
            if(root1 == NULL || root2 == NULL)
            return false;
            else
            {
                if(root1->val == root2->val)
                return _isSymmetric(root1->left, root2->right)&&
                       _isSymmetric(root1->right, root2->left);
                       else
                       return false;
            }
        }
    }
};
