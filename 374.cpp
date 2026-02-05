class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == 0) {
                return mid;          // found the number
            } 
            else if (res == -1) {
                high = mid - 1;      // mid is too high
            } 
            else {
                low = mid + 1;       // mid is too low
            }
        }
        return -1; // will never reach here
    }
};
