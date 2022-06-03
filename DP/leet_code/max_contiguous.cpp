#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,maxi;
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    int dp[9];
    // for(i=0;i<100;i++)
    //     cin>>a[i];
    dp[0]=a[0];
    for(i=1;i<9;i++)
    {
       if(a[i]+dp[i-1]>=a[i])
          dp[i]=a[i]+dp[i-1];
       else
          dp[i]=a[i];
       maxi=max(dp[i-1],dp[i]); 
    }
   cout<<maxi<<endl; 
}