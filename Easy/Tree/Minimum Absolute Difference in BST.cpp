class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vect;
        int mindiff = INT_MAX;

        explore(root,vect);
        for(int i=1; i<vect.size(); ++i){
            mindiff = min(mindiff,vect[i] - vect[i-1]);
        }
        return mindiff;
    }
    void explore(TreeNode* root,vector<int>& vect ){
        if(!root)return;
        explore(root->left,vect);
        vect.push_back(root->val);
        explore(root->right,vect);
    }
};
