class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int s = 0;
        for (int i = 0; i < k; i++)
        {
            s += nums[i];
        }
        int mxs = s;
        for (int i = k; i < nums.size(); i++)
        {
            s = s + nums[i] - nums[i - k];
            mxs = max(mxs, s);
        }
        return (double)mxs / k;
    }
};