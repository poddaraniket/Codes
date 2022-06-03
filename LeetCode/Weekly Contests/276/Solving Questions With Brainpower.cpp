//O(N)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int profit=questions[i][0];
            int dist=questions[i][1];
            int future=dist+i+1;
            if(future>=n){
                dp[i]=profit;
            }else{
                dp[i]=profit+dp[future];
            }
            dp[i]=max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};