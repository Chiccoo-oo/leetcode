class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
        }
        int r = s % k;
        return r;
    }
};