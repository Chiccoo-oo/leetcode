class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> freq;
        for (char ch : s)
        {
            freq[ch]++;
        }
        int length = 0;
        bool odd = false;
        for (auto &pair : freq)
        {
            int count = pair.second;
            length += (count / 2) * 2; // Add the even part

            if (count % 2 == 1)
            {
                odd = true; // At least one odd count exists
            }
        }
        if (odd)
        {
            length += 1;
        }

        return length;
    }
};