class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int cnt = 0;
        for (char c : word)
        {
            if (isupper(c))
            {
                cnt++;
            }
        }
        int n = word.length();
        if (cnt == n)
            return true;
        if (cnt == 0)
            return true;
        if (cnt == 1 && isupper(word[0]))
            return true;
        return false;
    }
};