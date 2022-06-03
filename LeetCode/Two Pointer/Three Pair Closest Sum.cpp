class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
       sort(nums.begin(),nums.end());
       int diff=1000000000; 
       int ans;
       for(int i=0;i<nums.size();i++)
       {
           int a=nums[i];
           int l=i+1,r=nums.size()-1;
           while(l<r)
           {
               int sum=a+nums[l]+nums[r];
               if(sum==target)
                   return sum;
               else if(sum>target)
               {
                   r--;
                   if(diff>(sum-target))
                   {
                       diff=sum-target;
                       ans=sum;
                   }
               }
               else
               {
                 l++;
                 if(diff>target-sum)
                 {
                     diff=target-sum;
                     ans=sum;
                 }
               }   
           } 
       }
      return ans;  
    }
};