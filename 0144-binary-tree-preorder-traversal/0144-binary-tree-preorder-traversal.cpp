class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root) {
        if(root == NULL)
            return;
        // 1. Left
        ans.push_back(root->val);
        // 2. Right
        solve(root->left);
        solve(root->right);
        // 3. Root
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};