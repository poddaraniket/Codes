class Solution {
public:
    
    int minCostUtil(int start,int end,vector<int> &cuts,vector<vector<int>> &dp){
        if(start>end){
            return 0; 
        }
        if(dp[start][end]!=-1)
           return dp[start][end];
        //k -> place where you make the cut 
        int mini=INT_MAX;
        for(int k=start;k<=end;k++){
            int leftCost=minCostUtil(start,k-1,cuts,dp);
            int cost=cuts[end+1]-cuts[start-1];
            int rightCost=minCostUtil(k+1,end,cuts,dp);
            mini=min(mini,leftCost+cost+rightCost);
        }
        dp[start][end]=mini;
        return dp[start][end];
    } 
    
    
    
    int minCost(int n, vector<int>& cuts) {
        int len=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(len+1,vector<int> (len+1,-1));
        int cost=minCostUtil(1,len,cuts,dp);   
        return cost;
    }
};