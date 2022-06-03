// finite supply ->2D
// just true/false -> combination take nums in row;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2){
            return false;
        }
        int target=sum/2;
        int n=nums.size();
        int dp[n+1][target+1];
        for(int i=1;i<=target;i++){
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};