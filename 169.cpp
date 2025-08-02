class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int s = nums.size();
        int n = s / 2;
        unordered_map<int, int> freq;
        for (int ch : nums)
        {
            freq[ch]++;
            if (freq[ch] > n)
            {
                return ch;
            }
        }
        return -1;
    }
};