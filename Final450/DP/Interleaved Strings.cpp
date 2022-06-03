// O(n^2)

bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n=A.length();
        int m=B.length();
        int dp[n+1][m+1];
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
         {
            if(A[i-1]==C[i-1])
             dp[i][0]=dp[i-1][0];
            else
             dp[i][0]=0;
         }
        for(int i=1;i<=m;i++)
         {
            if(B[i-1]==C[i-1])
             dp[0][i]=dp[0][i-1];
            else
             dp[0][i]=0; 
         }
        for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
              {
                  int k=(i+j);
                  if(A[i-1]==C[k-1]){
                     if(B[j-1]==C[k-1])
                      {
                        dp[i][j]=dp[i-1][j] || dp[i][j-1];  
                      }
                     else
                      dp[i][j]=dp[i-1][j];
                  }
                  else if(B[j-1]==C[k-1])
                   dp[i][j]=dp[i][j-1];
                  else
                   dp[i][j]=0;
              }
         }
        // for(int i=0;i<=n;i++)
        //  {
        //      for(int j=0;j<=m;j++)
        //       cout<<dp[i][j]<<" ";
        //     cout<<endl;  
        //  }
        return dp[n][m]; 
    }