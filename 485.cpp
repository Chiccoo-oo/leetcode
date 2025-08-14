class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int c = 0;    // current streak
        int maxc = 0; // max streak so far

        for (int num : nums)
        {
            if (num == 1)
            {
                c++;
                maxc = max(c, maxc); // update existing maxc, not redeclare it
            }
            else
            {
                c = 0; // reset streak
            }
        }

        return maxc;
    }
};
