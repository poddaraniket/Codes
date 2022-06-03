class Solution {
public:
    bool canJump(vector<int>& nums) {
      if(nums.size()==1)
          return true;
      int reach=nums.size()-1;
      for(int i=nums.size()-2;i>=0;i--)
       {
          if(nums[i]+i>=reach)
           {
              reach=i;
           } 
       }
      if(reach==0)  
       return true;
      return false;  
    }
};