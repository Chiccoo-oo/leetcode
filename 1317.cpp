class Solution
{
public:
    bool zero(int n)
    {
        while (n > 0)
        {
            if (n % 10 == 0)
                return true;
            n /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = n - i;
            if (!zero(i) && !zero(j))
            {
                return {i, j};
            }
        }
        return {};
    }
};