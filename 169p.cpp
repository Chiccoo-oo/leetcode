class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ca = 0;
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (c == 0)
            {
                ca = nums[i];
            }
            if (nums[i] == ca)
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        return ca;
    }
};