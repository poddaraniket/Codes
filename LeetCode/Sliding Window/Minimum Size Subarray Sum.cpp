class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {   
     int begin=0,sum=0,window_size=nums.size()+2;
     for(int end=0;end<nums.size();end++)
     {
         sum+=nums[end];
         while(sum>=s)
          {
             window_size=min(window_size,end-begin+1);
             sum-=nums[begin];
             begin++;
          }
     }
    if(window_size>nums.size())
        return 0;
    return window_size;    
    }
};