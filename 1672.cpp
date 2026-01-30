class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int m = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int s = 0;
            for (int j = 0; j < accounts[i].size(); j++)
            {
                s = s + accounts[i][j];
                m = max(m, s);
            }
        }
        return m;
    }
};