class Solution
{
public:
    static bool c(int a, int b)
    {
        return abs(a) > abs(b);
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), c);
        long long s = 0;
        int n = nums.size();
        int p = (n + 1) / 2;
        for (int i = 0; i < p; i++)
        {
            s += (long long)nums[i] * nums[i];
        }
        for (int i = p; i < n; i++)
        {
            s -= (long long)nums[i] * nums[i];
        }
        return s;
    }
}