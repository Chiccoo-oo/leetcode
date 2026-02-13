class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0;                       // FIXED
        int r = numbers.size() - 1;      // FIXED

        while(l < r){

            if(numbers[l] + numbers[r] == target)
                return {l+1, r+1};       // FIXED

            else if(numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        return {};                       // FIXED
    }
};
