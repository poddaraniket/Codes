#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      int n,i;
      cin>>n;
      int dp[n+1],temp;
      if(n<7)
       cout<<n<<endl;
      else
       {
      for(i=0;i<7;i++)
       dp[i]=i;
      for(i=7;i<=n;i++)
       {
         dp[i]=max(2*dp[i-3],max(3*dp[i-4],4*dp[i-5]));
       }
    //   for(i=0;i<=n;i++)
        cout<<dp[n]<<endl;
       }
       
     }
}