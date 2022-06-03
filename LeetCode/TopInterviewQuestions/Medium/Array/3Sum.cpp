class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int l = i + 1, r = n-1;
                while(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum == 0){
                        result.push_back({nums[i], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1])
                        {
                            l++;
                        } 
                        while(l < r && nums[r] == nums[r-1]){
                            r--;
                        } 
                        l++; 
                        r--;
                    }
                    else if (sum > 0) r--;
                    else l++;
                }
            }
        }
        return result;
    }
};