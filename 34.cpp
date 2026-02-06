class Solution
{
public:
    int lowerBound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};

        int left = lowerBound(nums, target);

        if (left == n || nums[left] != target)
            return {-1, -1};

        int right = upperBound(nums, target) - 1;

        return {left, right};
    }
};
