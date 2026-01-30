class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int c = 0;
        int m = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            c = c + gain[i];
            m = max(c, m);
        }
        return m;
    }
};