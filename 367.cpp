class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long left = 1;
        long long right = num;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long s = mid * mid;
            if (s == num)
                return mid;
            else if (s < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};