class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int c = 0;   
        int maxc = 0; 

        for (int num : nums)
        {
            if (num == 1)
            {
                c++;
                maxc = max(c, maxc); 
            }
            else
            {
                c = 0; 
            }
        }

        return maxc;
    }
};
