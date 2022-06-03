#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	    int n,m,t,i,j;
	    cin>>n>>m;
	    t=(m+n)-2;
	    if(t>0)
	    {
	    int dp[t+1][m];
         //int dp[n+1][k+1];
         //dp[0][0]=1;
         for(i=0;i<m;i++)
          dp[0][i]=0;
         for(i=1;i<=t;i++)
          {
              for(j=0;j<=min(i,m);j++)
               {
                  if(i!=j && j!=0)
                  {
                   dp[i][j]=((dp[i-1][j-1] % 1000000007)+(dp[i-1][j]%1000000007))%1000000007;  
                  }
                  else
                   dp[i][j]=1;
               }
          }
        // for(i=1;i<=t;i++)
        //   {
        //       for(j=0;j<m;j++)
        //       cout<<dp[i][j]<<" ";
        //       cout<<endl; 
        //   }
        cout<<dp[t][m-1]<<endl;
	  }
	 else
	   cout<<"1"<<endl;
	 }
	return 0;
}
