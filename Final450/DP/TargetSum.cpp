class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // lets divide pos and neg assigned in two sets S1 & S2
        // S1+S2=Sum of all Arrays
        // S1-S2=target[S2 all negative]
        // S1-(Sum-S1)=target => S1=(target+Sum)/2;
        // find all possible sets that sum up to (target+Sum)/2;
        
        if(nums.size()==1)
        {
            return nums[0]==abs(target)?1:0;
        }
        // sort(v.begin(),v.end());
        int sum=0,countZero=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
         {
            if(nums[i]==0)
                countZero++;
            else
                v.push_back(nums[i]); 
            sum+=nums[i];   
         }
        if((sum+target)%2!=0)
            return 0; 
        int val=(sum+target)/2;
        
        // Knapsack [pick that number or not]
        int n=v.size();
        int dp[n+1][val+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[i][0]=1; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=val;j++)
            {
                if(v[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];
                }
                else
                     dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][val]*(pow(2,countZero));
    }
};