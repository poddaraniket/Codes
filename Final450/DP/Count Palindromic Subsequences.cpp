long long int  countPS(string str)
    {
       //Your code here
       long long int len=str.length();
       long long int dp[len+1][len+1];
       memset(dp,0,sizeof(dp));
       for(long long int i=0;i<len;i++){
           dp[i][i]=1;
       }
       for(long long int cl=2;cl<=len;cl++)
        {
           for(long long int i=0;i<=len-cl;i++)
            {
                int j=cl+i-1;
                if(str[i]==str[j]){
                    // + 1 bcoz of str[i] amd str[j]
                    dp[i][j]=(dp[i+1][j]+dp[i][j-1]+1)%1000000007;
                }
                else{
                    dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%1000000007;
                }
            }
        }
        return dp[0][len-1];
    }