//O(N) - > kadane Algo

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far=nums[0];
        int curr_max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(max_so_far<curr_max){
                max_so_far=curr_max;
            }
            if(curr_max<0)
                curr_max=0;
            curr_max+=nums[i];
        }
        return max(max_so_far,curr_max);
    }
};