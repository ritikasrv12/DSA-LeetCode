class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode* , int> > q;
        q.push({root , 1});
        long long int levelSum[10001];
        int maxLevel = 1;

        for(int i=0; i<10001; i++) levelSum[i] = 0;

        while(!q.empty())
        {
           TreeNode*node = q.front().first;
           int level = q.front().second; 
           maxLevel = max(maxLevel , level);

          q.pop();

         levelSum[level] += node->val;

         if(node->left != nullptr) q.push({node->left, level+1});
         if(node->right != nullptr) q.push({node->right, level+1});
        }
        int mx = -100000;
        int res = 1;

        for(int i=1; i<=maxLevel; i++)
        {
            if(levelSum[i] > mx)
            {
                mx = levelSum[i];
                res = i;
            }
        }
        return res;
    }
};
