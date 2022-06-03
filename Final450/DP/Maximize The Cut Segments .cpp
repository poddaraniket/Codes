int length[3]={x,y,z};
        int dp[n+1]={0};
        for(int i=0;i<3;i++){
            for(int j=0;j<=n;j++){
                if(length[i]<j && dp[j-length[i]]!=0)
                 dp[j]=max(dp[j],dp[j-length[i]]+1);
                else if(length[i]==j)
                 dp[j]=max(dp[j],1);
            }
        }
        // for(int i=0;i<=n;i++) 
        //  cout<<dp[i]<<" ";
        // cout<<endl; 
        return dp[n];