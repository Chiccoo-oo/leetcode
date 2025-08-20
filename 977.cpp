class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = n - 1;
        vector<int> result(n);
        while (left <= right)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                result[pos] = nums[left] * nums[left];
                left++;
            }
            else
            {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
        return result;
    }
};