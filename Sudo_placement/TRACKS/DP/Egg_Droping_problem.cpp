#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) 
{
    // your code here
    int i,j,l;
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(i=0;i<=n;i++)
     dp[i][0]=0;
    for(i=0;i<=k;i++)
     dp[0][i]=0;
    for(i=0;i<=k;i++)  //one egg k floors
     dp[1][i]=i;
    for(i=2;i<=n;i++)
     {
        for(j=1;j<=k;j++)
         {
            int mini=10000000; 
            if(i>j)
             dp[i][j]=dp[i-1][j];
            else
             {
              for(l=1;l<=j;l++)   // at every floor we will check if egg breaks here or not
               {
                 int t=max(dp[i-1][l-1],dp[i][j-l]);
                 mini=min(mini,t);
               }
              dp[i][j]=1+mini;  
             }
         }
     }
    return dp[n][k]; 
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends