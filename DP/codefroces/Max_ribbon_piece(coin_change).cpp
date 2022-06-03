#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n,a[3],i,j;
  cin>>n>>a[0]>>a[1]>>a[2];
  int dp[n+1]={0};
  //dp[0]=1;
  for(i=0;i<3;i++)
   {
     if(a[i]<=n)
      dp[a[i]]=1;
     for(j=1;j<=n;j++)
      {
        if(a[i]<=j)
         {
            if(dp[(j-a[i])]!=0) 
               dp[j]=max(dp[j],dp[j-a[i]]+1);
            //cout<<j<<"->"<<dp[j]<<endl; 
         }
      }
   }
  cout<<dp[n]<<endl;  
}