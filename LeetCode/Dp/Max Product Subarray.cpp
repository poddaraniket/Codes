class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int min_val=nums[0],max_val=nums[0],ans=nums[0];
      for(int i=1;i<nums.size();i++)
      {
          if(nums[i]<0)
          {
              int temp=min_val;
              min_val=max_val;
              max_val=temp;
          }
          max_val=max(nums[i],nums[i]*max_val); // keep curr max value
          min_val=min(nums[i],nums[i]*min_val); // keep curr min val
          ans=max(ans,max_val); //keep over all max value
      }
      return ans;
    }
};