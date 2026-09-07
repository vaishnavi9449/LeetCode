class Solution {
public:
    int max_sum = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        // Ignore negative paths
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        // Maximum path passing through current node
        int currentSum = root->val + left + right;
        // Update global maximum
        max_sum = max(max_sum, currentSum);
        // Return maximum one-side path to parent
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};