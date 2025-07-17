class Solution
{
public:
    // Function to find the maximum length of a subsequence with elements having a given modulus
    int maximumLength(std::vector<int> &nums, int k)
    {
        // Initialize a 2D array to store intermediate results
        int remainderCount[k][k];

        // Set all elements of the 2D array to 0
        std::memset(remainderCount, 0, sizeof(remainderCount));

        int maxLength = 0; // Variable to keep track of the maximum length

        // Iterate through each number in the input vector
        for (int num : nums)
        {
            int modValue = num % k; // Calculate modulus of the number with respect to k

            // Loop through possible remainder values
            for (int remainder = 0; remainder < k; ++remainder)
            {
                // Calculate the target remainder
                int targetRemainder = (remainder - modValue + k) % k;

                // Update the 2D array for the current modValue and targetRemainder
                remainderCount[modValue][targetRemainder] = remainderCount[targetRemainder][modValue] + 1;

                // Update maximum length if a longer subsequence is found
                maxLength = std::max(maxLength, remainderCount[modValue][targetRemainder]);
            }
        }

        // Return the maximum length of the subsequence found
        return maxLength;
    }
};
