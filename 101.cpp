class Solution
{
public:
    bool mirror(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2)
            return true; // both null → symmetric
        if (!t1 || !t2)
            return false; // one null → not symmetric
        return (t1->val == t2->val) &&
               mirror(t1->left, t2->right) &&
               mirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true; // empty tree is symmetric
        return mirror(root->left, root->right);
    }
};
