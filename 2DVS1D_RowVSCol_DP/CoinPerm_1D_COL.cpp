// since we have infinte supply we use 1D
// Use coins as column as we need permutation
// make sure ki wo har ek possible coin kai saath aye
int combinationSum4(vector<int>& coins, int amount) {
        int n=coins.size();
        long long int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=amount;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(coins[j-1]<=i)
                {
                    dp[i]=(dp[i]+dp[i-coins[j-1]])%(long long int)pow(2,32);
                }
            }
        } 
        return (int)dp[amount];
    }