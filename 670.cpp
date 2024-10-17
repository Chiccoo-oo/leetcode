class Solution
{
public:
    int maximumSwap(int num)
    {
        string digits = to_string(num);
        vector<int> last(10, -1);
        for (int i = 0; i < digits.size(); ++i)
        {
            last[digits[i] - '0'] = i;
        }
        for (int i = 0; i < digits.size(); ++i)
        {
            for (int d = 9; d > digits[i] - '0'; --d)
            {
                if (last[d] > i)
                {
                    swap(digits[i], digits[last[d]]);
                    return stoi(digits);
                }
            }
        }
        return num;
    }
};