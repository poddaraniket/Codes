int countFriendsPairings(int n) 
    { 
        // code here
        if(n==1)
         return 1;
        if(n==2)
         return 2;
        long long int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         {
            dp[i]=((((i-1)*dp[i-2])%1000000007)+dp[i-1])%1000000007; 
         }
        return (int)dp[n]; 
    }