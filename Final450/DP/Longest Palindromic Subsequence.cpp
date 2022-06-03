int longestPalinSubseq (string S)
{
    // your code here
    int n=S.length();
    int dp[n][n];
    for(int i=0;i<n;i++)
     dp[i][i]=1;
    for(int l=2;l<=n;l++)
     {
        for(int i=0;i<=n-l;i++)
         {
            int j=i+l-1; 
            if(S[i]==S[j] && l==2)
             dp[i][j]=2;
            else if(S[i]==S[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            } 
            else
             dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
         }
     }
    return dp[0][n-1]; 
}