class Solution {
public:
    bool canJump(vector<int>& nums) {
      if(nums.size()==1)
          return true;
      if(nums[0]==0)
          return false;
      int max_reacheable=0;
// max projectile distance 
      for(int i=0;i<nums.size()-1;i++)
       {
          if(i>max_reacheable)
              return false;
          if(nums[i]!=0 && nums[i]+i>max_reacheable)
           {
              max_reacheable=nums[i]+i;
           }
          if(max_reacheable>=nums.size()-1)
              return true;
       }
      return false;  
    }
};