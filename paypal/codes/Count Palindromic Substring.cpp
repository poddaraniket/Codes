int CountPS(char str[], int n)
{
    //code here
    bool dp[n][n]={false};
    for(int i=0;i<n;i++)
     {
        dp[i][i]=true; 
     }
    int count=0; 
    for(int k=2;k<=n;k++)
     {
        for(int i=0;i<=n-k;i++)
         {
            int j=i+k-1;
            if(str[i]==str[j])
             {
                if(k==2)
                 dp[i][j]=true;
                else
                 {
                    dp[i][j]=dp[i+1][j-1]; 
                 }
             }
            else
             {
                dp[i][j]=false; 
             }
            if(dp[i][j] && j-i+1>=2){
             count++;
         }
     }
    }
    return count;
    
}