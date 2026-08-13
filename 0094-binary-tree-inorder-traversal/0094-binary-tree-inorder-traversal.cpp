class Solution {
public:
    vector<int> ans;

    void solve(TreeNode* root) {
        if(root == NULL)
            return;
        // 1. Left
        solve(root->left);
        // 2. Right
        ans.push_back(root->val);
        // 3. Root
        solve(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};