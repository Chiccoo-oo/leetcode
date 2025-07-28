class Solution
{
public:
    bool isPalindrome(string s)
    {
        string filtered = "";
        for (char c : s)
        {
            if (isalnum(c))
            {
                filtered += tolower(c);
            }
        }
        int left = 0;
        int right;
        right = filtered.size() - 1;
        while (left < right)
        {
            if (filtered[left] != filtered[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};