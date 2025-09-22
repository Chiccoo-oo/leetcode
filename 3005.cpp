class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> f;
        for (int x : nums)
        {
            f[x]++;
        }
        int mf = 0;
        for (auto &p : f)
        {
            mf = max(mf, p.second);
        }
        int a = 0;
        for (auto &p : f)
        {
            if (p.second == mf)
            {
                a += p.second;
            }
        }
        return a;
    }
};