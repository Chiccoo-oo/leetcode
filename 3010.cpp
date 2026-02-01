class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        int m = INT_MAX;
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                int c = nums[0] + nums[i] + nums[j];
                m = min(m, c);
            }
        }
        return m;
    }
};