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
 std::unordered_map<TreeNode*, std::pair<int, int>> memo;
    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the sum and count of nodes in the left and right subtrees
        int leftSum = 0, leftCount = 0, rightSum = 0, rightCount = 0;
        if (root->left) {
            std::pair<int, int> leftData = getSubtreeData(root->left);
            leftSum = leftData.first;
            leftCount = leftData.second;
        }
        if (root->right) {
            std::pair<int, int> rightData = getSubtreeData(root->right);
            rightSum = rightData.first;
            rightCount = rightData.second;
        }

        // Calculate the total sum and count of the current node and its subtrees
        int totalSum = root->val + leftSum + rightSum;
        int totalCount = 1 + leftCount + rightCount;

        // Calculate the average and initialize the answer
        int average = totalSum / totalCount;
        int answer = 0;

        // Check if the current node's value matches the calculated average
        if (root->val == average) {
            answer = 1;
        }

        // Recursively calculate the answer for the left and right subtrees
        answer += averageOfSubtree(root->left) + averageOfSubtree(root->right);

        return answer;
    }

    // Helper function to memoize subtree data
    std::pair<int, int> getSubtreeData(TreeNode* node) {
        if (memo.find(node) != memo.end()) {
            return memo[node];
        }
        int sum = node->val;
        int count = 1;
        if (node->left) {
            std::pair<int, int> leftData = getSubtreeData(node->left);
            sum += leftData.first;
            count += leftData.second;
        }
        if (node->right) {
            std::pair<int, int> rightData = getSubtreeData(node->right);
            sum += rightData.first;
            count += rightData.second;
        }
        memo[node] = std::make_pair(sum, count);
        return memo[node];
        
    }
};
