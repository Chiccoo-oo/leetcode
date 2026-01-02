class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int size = nums.size();

        for (int i = 0; i < size - 2; i++)
        {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
            {
                return nums[i];
            }
        }

        // Edge case (though problem guarantees a solution)
        return nums[size - 1];
    }
};
