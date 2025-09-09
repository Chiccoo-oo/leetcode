class Solution
{
public:
    bool isHappy(int n)
    {
        int s = squared(n);
        int f = squared(squared(n));
        while (s != f)
        {
            s = squared(s);
            f = squared(squared(f));
        }
        return s == 1;
    }

private:
    int squared(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};