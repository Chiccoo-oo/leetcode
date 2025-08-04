class Solution
{
public:
    int max_d = 0;
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        max_d = max(max_d, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return max_d;
    }
};