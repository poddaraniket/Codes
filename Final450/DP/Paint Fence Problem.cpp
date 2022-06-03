long long countWays(int n, int k){
        // code here
        if(n==1)
         return k;
        long long dp[2][n+1];
        dp[0][2]=k;
        dp[1][2]=k*(k-1);
        for(int i=3;i<=n;i++){
            dp[0][i]=dp[1][i-1];
            dp[1][i]=(((dp[0][i-1]+dp[1][i-1])%1000000007)*(k-1))%1000000007;
        }
        return (dp[0][n]+dp[1][n])%1000000007;
    }