class Solution
{
public:
    string sortVowels(string s)
    {
        auto isVowel = [](char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };

        // 1. collect vowels
        vector<char> vowels;
        for (char c : s)
        {
            if (isVowel(c))
                vowels.push_back(c);
        }

        // 2. sort vowels
        sort(vowels.begin(), vowels.end());

        // 3. replace vowels in order
        int idx = 0;
        for (char &c : s)
        {
            if (isVowel(c))
            {
                c = vowels[idx++];
            }
        }

        return s;
    }
};
