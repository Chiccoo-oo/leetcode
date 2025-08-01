class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int freq[26] = {0}; // For letters a-z

        for (char ch : magazine)
        {
            freq[ch - 'a']++; // Count letters in magazine
        }

        for (char ch : ransomNote)
        {
            if (freq[ch - 'a'] == 0)
            {
                return false; // Not enough of this letter
            }
            freq[ch - 'a']--; // Use one letter
        }

        return true;
    }
};
