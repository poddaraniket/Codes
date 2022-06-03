

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i=0;i<=amount;i++){
            dp[i]=100000000;
        }
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j){
                    // cout<<dp[j-coins[i]]<<endl;
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        return dp[amount]==100000000 ? -1 : dp[amount];
    }
};