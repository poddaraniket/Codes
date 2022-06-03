class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i]=i;
        }
        for(int i=2;i*i<=n;i++){
            for(int j=1;j<=n;j++){
                int val=i*i;
                if(val<=j){
                    dp[j]=min(dp[j-val]+1,dp[j]);
                }
            }
        }
        return dp[n];
    }
};