class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        // Visit right subtree first (greater values)
        convertBST(root->right);
        // Update current node
        sum += root->val;
        root->val = sum;
        // Visit left subtree
        convertBST(root->left);
        return root;
    }
};