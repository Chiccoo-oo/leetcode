class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int rh = 0;
        while (x > rh)
        {
            rh = rh * 10 + x % 10;
            x /= 10;
        }
        return (rh == x || x == rh / 10);
    }
};