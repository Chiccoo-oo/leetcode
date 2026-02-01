class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int m = nums[0];
        int maxIndex = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > m)
            {
                m = nums[i];
                maxIndex = i;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i != maxIndex && m < 2 * nums[i])
            {
                return -1;
            }
        }

        return maxIndex;
    }
};
