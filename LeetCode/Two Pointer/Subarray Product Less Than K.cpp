class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       if(k<=1)
           return 0;
       int l=0,r=0; 
       int c=0; 
       int pro=1;
       while(r<nums.size())
       {
          pro*=nums[r];
          while(l<r && pro>=k)
          {
             pro/=nums[l]; 
             l++; 
          }
          if(pro<k) 
           c+=(r-l)+1;  // it adds up all the possiblilities from l to r taking middle,corner all possible subsets
          r++;
       } 
      return c;   
    }
};