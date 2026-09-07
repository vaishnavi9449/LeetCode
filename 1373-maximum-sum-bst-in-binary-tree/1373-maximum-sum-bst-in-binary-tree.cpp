/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int max_sum = 0;
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
    Info dfs(TreeNode* root) {
        // Empty tree is a valid BST
        if (root == NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        // Check BST condition
        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {
            int currentSum = left.sum + right.sum + root->val;
            max_sum = max(max_sum, currentSum);
            return {
                true,
                currentSum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            };
        }
        // Not a BST
        return {false, 0, INT_MIN, INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};