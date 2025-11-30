class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        long long total = 0;

        // 1. Find total sum
        for (int x : nums)
            total += x;

        // 2. Remainder we need to remove
        int need = total % p;

        // If already divisible, remove nothing
        if (need == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1; // base case for subarrays starting at index 0

        long long prefix = 0;
        int n = nums.size();
        int ans = n; // initialize with maximum possible size

        // 3. Traverse and apply prefix sum logic
        for (int i = 0; i < n; i++)
        {
            prefix = (prefix + nums[i]) % p;

            int target = (prefix - need + p) % p;

            // If we have seen this target before, update answer
            if (mp.find(target) != mp.end())
            {
                ans = min(ans, i - mp[target]);
            }

            // Store current prefix modulo
            mp[prefix] = i;
        }

        // 4. If we must remove the whole array, return -1
        return (ans == n) ? -1 : ans;
    }
};