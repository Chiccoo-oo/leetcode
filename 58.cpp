class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        int c = 0;
        while (i >= 0 && s[i] != ' ')
        {
            c++;
            i--;
        }
        return c;
    }
};