class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        // Sort the array to enable binary search and range calculations
        ranges::sort(nums);
      
        // Track the maximum number of elements that can form a valid subarray
        int maxValidElements = 0;
        int n = nums.size();
      
        // For each element as the minimum value of a potential subarray
        for (int i = 0; i < n; ++i) {
            // Find the rightmost position where elements are still within k times the minimum
            int rightBoundary = n;
          
            // Check if the maximum possible value (nums[i] * k) is within array bounds
            // Use 1LL to prevent integer overflow during multiplication
            if (1LL * nums[i] * k <= nums[n - 1]) {
                // Binary search for the first element greater than nums[i] * k
                rightBoundary = upper_bound(nums.begin(), nums.end(), 1LL * nums[i] * k) - nums.begin();
            }
          
            // Update the maximum count of valid elements in a subarray
            // The valid range is from index i to rightBoundary (exclusive)
            maxValidElements = max(maxValidElements, rightBoundary - i);
        }
      
        // Return minimum removals needed (total elements minus maximum valid subarray)
        return n - maxValidElements;
    }
};