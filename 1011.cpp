class Solution
{
public:
    int d(vector<int> &w, int c)
    {
        int day = 1;
        int l = 0;
        for (int we : w)
        {
            if (l + we > c)
            {
                day++;
                l = 0;
            }
            l += we;
        }
        return day;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int le = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (le < r)
        {
            int mid = le + (r - le) / 2;
            if (d(weights, mid) <= days)
            {
                r = mid;
            }
            else
            {
                le = mid + 1;
            }
        }
        return le;
    }
};