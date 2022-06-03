class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        // if N=4 we have 3 matrix
        int n=N-1;
        int dp[n][n];
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
               if(gap==0){
                   dp[i][j]=0;
               }else if(gap==1){
                   dp[i][j]=arr[i]*arr[j]*arr[j+1];
               }else{
                   dp[i][j]=INT_MAX;
                   for(int k=i;k<j;k++){
                       int lc=dp[i][k];
                       int rc=dp[k+1][j];
                       int m=arr[i]*arr[k+1]*arr[j+1];
                       dp[i][j]=min(dp[i][j],lc+rc+m);
                   }
               }
            }
        }
        return dp[0][n-1];
        
    }