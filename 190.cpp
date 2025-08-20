class Solution
{
public:
    int reverseBits(int n)
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++)
        {
            int b = n & 1;
            result <<= 1;
            result |= b;
            n >>= 1;
        }
        return result;
    }
};