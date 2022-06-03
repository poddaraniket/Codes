//O(N)
int robsUtil(vector<int>& nums,int s,int e)
    {
        int n=e-s+1;
        int dp[n];
        dp[0]=nums[s];
        if(n>1)
           dp[1]=max(nums[s],nums[s+1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[s+i],dp[i-1]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
           return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        if(n==3)
             return max(nums[0],max(nums[2],nums[1]));
        int leaveLast=robsUtil(nums,0,n-2);
        int takeLast=robsUtil(nums,1,n-1);
        return max(leaveLast,takeLast);
    }