long long int count( int S[], int m, int n )
    {
       
        //code here.
        long long int dp[n+1]={0};
        for(int j=0;j<m;j++)
        {
          for(int i=1;i<=n;i++)
          {
            if(i>S[j])
            {
              dp[i]+=dp[i-S[j]];
            }
            else if(i==S[j])
             dp[i]+=1;
          }
        }
        return dp[n];
    }