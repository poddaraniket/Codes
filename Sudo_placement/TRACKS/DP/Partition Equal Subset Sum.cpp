class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
         {
            sum+=nums[i];
         }
        if(sum%2!=0)
            return false;
        sum/=2;
        bool dp[sum+1][nums.size()+1];
        for(int i=0;i<=sum;i++)
           dp[i][0]=false;
        for(int i=0;i<=nums.size();i++)
           dp[0][i]=true;
        dp[0][0]=true;
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=nums.size();j++)
            {
                if(i<nums[j-1])
                    dp[i][j]=dp[i][j-1];
                else
                    dp[i][j]=dp[i-nums[j-1]][j-1] || dp[i][j-1];
            }
        }
        return dp[sum][nums.size()];
    }
};