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
class Solution
{
public:
    int check(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = check(root->left);
        int right = check(root->right);
        if (left == -1 || right == -1)
        {
            return -1;
        }
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return check(root) != -1;
    }
};

class Solution
{
public:
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);

        return 1 + max(leftDepth, rightDepth);
    }

    int maxDepth(TreeNode *root)
    {
        return dfs(root);
    }
};
