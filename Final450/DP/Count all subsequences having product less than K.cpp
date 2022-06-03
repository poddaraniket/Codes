int countSubSequenceProductLessThanK(const vector<int>& a, int n, long long k) {
        int dp[k+1][n+1];
        memset(dp,0,sizeof(dp));
        for(long long i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1];
                if(a[j-1]<=i)
                 dp[i][j]+=dp[i/a[j-1]][j-1]+1;
            }
        }
        return dp[k][n];
    }