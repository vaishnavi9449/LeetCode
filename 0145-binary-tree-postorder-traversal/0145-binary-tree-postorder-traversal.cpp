class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root) {
        if(root == NULL)
            return;
        // 1. Left
        solve(root->left);
        // 2. Right
        solve(root->right);
        // 3. Root
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};