class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                long long nt = (long long)target - nums[i] - nums[j];

                int l = j+1;
                int r = n-1;

                while(l < r){
                    long long s = nums[l] + nums[r];

                    if(s < nt) l++;
                    else if(s > nt) r--;
                    else{
                        re.push_back({nums[i], nums[j], nums[l], nums[r]});

                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;

                        l++;
                        r--;
                    }
                }
            }
        }
        return re;
    }
};