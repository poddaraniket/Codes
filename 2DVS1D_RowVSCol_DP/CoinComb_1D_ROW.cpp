int change(int amount, vector<int>& coins) {
        // since we have infinte supply we use 1D
        // Use coins as row as we need combination
        // make sure ki wo ek particular coin kai baad hi aye(removing permutation)
        int n=coins.size();
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                    dp[j]=dp[j]+dp[j-coins[i-1]]; 
            }
        }
        return dp[amount];
    }