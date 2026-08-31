class Solution {
public:
    void inorder(TreeNode* root, TreeNode*& curr) {
        if (root == nullptr)
            return;
        // Left
        inorder(root->left, curr);
        // Process
        curr->right = root;
        root->left = nullptr;
        curr = root;
        // Right
        inorder(root->right, curr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;
        inorder(root, curr);
        return dummy->right;
    }
};