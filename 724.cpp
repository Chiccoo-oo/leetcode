class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int l = 0;
        int t = 0;
        for (int x : nums)
            t += x;
        for (int i = 0; i < nums.size(); i++)
        {
            if (l == t - l - nums[i])
                return i;
            l += nums[i];
        }
        return -1;
    }
};