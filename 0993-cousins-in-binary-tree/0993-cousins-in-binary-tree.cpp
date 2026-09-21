class Solution {
public:
    int depthx = -1, depthy = -1;
    TreeNode* Parentx = NULL;
    TreeNode* Parenty = NULL;
    void DFS(TreeNode* root, TreeNode* parent, int depth, int x, int y) {
        if (root == NULL)
            return;
        if (root->val == x) {
            depthx = depth;
            Parentx = parent;
        }
        if (root->val == y) {
            depthy = depth;
            Parenty = parent;
        }
        DFS(root->left, root, depth + 1, x, y);
        DFS(root->right, root, depth + 1, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        DFS(root, NULL, 0, x, y);
        return (depthx == depthy && Parentx != Parenty);
    }
};