class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int p = 0, c = 1;
        int a = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                c++;
            }
            else
            {
                a += min(c, p);
                p = c;
                c = 1;
            }
        }
        a += min(c, p);
        return a;
    }
};