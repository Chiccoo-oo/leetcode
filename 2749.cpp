class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {

        for (long ops = 0; ops <= 60; ++ops)
        {
            const long target = num1 - ops * num2;
            if (__builtin_popcountl(target) <= ops && ops <= target)
                return ops;
        }

        return -1;
    }
};
