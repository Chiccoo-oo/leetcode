class Solution
{
public:
    TreeNode *sortedArrayToBST(const vector<int> &nums)
    {
        return buildt(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildt(const vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildt(nums, left, mid - 1);
        root->right = buildt(nums, mid + 1, right);

        return root;
    }
};
