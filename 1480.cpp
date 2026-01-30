class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> r(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            r[i] = sum;
        }
        return r;
    }
};