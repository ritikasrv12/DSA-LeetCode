class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return bst(root,LONG_MIN, LONG_MAX);
        
    }
    bool bst(TreeNode* root,long int min,long int max){
        if(root==NULL)return true;

        if(root->val<=min || root->val>=max)return false;

        return(bst(root->left,min,root->val)&&bst(root->right,root->val,max));
    }
};
