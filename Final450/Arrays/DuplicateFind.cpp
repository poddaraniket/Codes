//O(N)->time , O(1)->space

int findDuplicate(vector<int>& nums) {
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]>=0){
                nums[abs(nums[i])-1]=nums[abs(nums[i])-1]*-1;
            }else{
               ans=abs(nums[i]);
            }
        }
        return ans;
    }