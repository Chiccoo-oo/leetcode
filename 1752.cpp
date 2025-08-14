class Solution
{
public:
    bool check(vector<int> &nums)
    {
        const int n = nums.size();
        int rotates = 0;

        for (int i = 0; i < n; ++i)
            if (nums[i] > nums[(i + 1) % n] && ++rotates > 1)
                return false;

        return true;
    }
};

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                count++;
            }
        }

        return count <= 1;
    }
};
