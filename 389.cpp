class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int freq[26] = {0};

        // count characters in s
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        // subtract using t
        for (char c : t)
        {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0)
            {
                return c; // extra character
            }
        }

        return ' '; // will never reach here
    }
};
