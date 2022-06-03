class Solution {
public:
    
    int last_exculde(int dp[],int n,vector<int>& nums)
     {
        dp[0]=nums[0];
        dp[1]=nums[0];
        for(int i=2;i<n-1;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-2];
     }
    
    int first_exculde(int dp[],int n,vector<int>& nums)
     {
        dp[1]=nums[1];
        dp[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
     }
     
    int rob(vector<int>& nums) {
        int dp[nums.size()],a;
        if(nums.size()==1)
          return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        a=max(first_exculde(dp,nums.size(),nums),last_exculde(dp,nums.size(),nums));
//         if(nums[1]>nums[0])
//          {
//             dp[0]=nums[0];
//             dp[1]=nums[1];
//             for(int i=2;i<nums.size();i++)
//              {
//                 dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
//              }
//             a=dp[nums.size()-1];
//          }
//         else
//          {
            
//          }
        return a;
    }
};