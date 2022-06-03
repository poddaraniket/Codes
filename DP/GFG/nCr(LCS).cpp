#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
     {
         int n,k,i,j;
         cin>>n>>k;
         if(n<k)
          cout<<"0"<<endl;
         else 
         {
         int dp[n+1][k+1];
         //dp[0][0]=1;
         for(i=0;i<=k;i++)
          dp[0][i]=0;
         for(i=1;i<=n;i++)
          {
              for(j=0;j<=min(i,k);j++)
               {
                  if(i!=j && j!=0)
                  {
                   dp[i][j]=((dp[i-1][j-1] % 1000000007)+(dp[i-1][j]%1000000007))%1000000007;  
                  }
                  else
                   dp[i][j]=1;
               }
          }
        cout<<dp[n][k]<<endl;
        }
     }
	return 0;
}
