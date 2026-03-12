class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        int sign = 1;

        if (i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+')
        {
            i++;
        }
        long long num = 0;
        while (i < n && isdigit(s[i]))
        {
            int d = s[i] - '0';
            num = num * 10 + d;
            if (sign * num > INT_MAX)
                return INT_MAX;
            if (sign * num < INT_MIN)
                return INT_MIN;

            i++;
        }
        return sign * num;
    }
};