#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
       int n,a[3],i,j;
       cin>>n;
       int dp[n+1]={0};
       dp[0]=1;
       a[0]=3;
       a[1]=5;
       a[2]=10;
       for(i=0;i<3;i++)
        {
            for(j=0;j<=n;j++)
             {
                 if(a[i]<=j)
                  dp[j]+=dp[j-a[i]];
             }
        }
      cout<<dp[n]<<endl;
     }
}