int dp[k+1][n+1];
         for(int i=0;i<=n;i++)
          dp[0][i]=0;
         for(int i=0;i<=k;i++)
          dp[i][0]=0;
         for(int i=1;i<=k;i++)
          {
              for(int j=1;j<=n;j++)
               {
                   if(i==1)
                   {
                    dp[i][j]=1;
                    continue;
                   }
                   if(j<i)
                    dp[i][j]=0;
                   else if(i==j)
                    dp[i][j]=1;
                   else
                    dp[i][j]=dp[i][j-1]*(i+1)+dp[i-1][j-1];
               }
          }
        return dp[k][n];  
    }