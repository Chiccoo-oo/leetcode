class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cs = nums[0];
        int ms = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            cs = max(nums[i], cs + nums[i]);
            ms = max(ms, cs);
        }
        return ms;
    }
};