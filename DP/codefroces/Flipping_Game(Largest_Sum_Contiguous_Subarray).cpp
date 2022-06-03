#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 int n,i,maxi=-1,sum=0,c=0;
 cin>>n;
 int a[n];
 int dp[n];
 for(i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]==0)
     dp[i]=1;
    else
     {
        c++;
        dp[i]=-1;
     }
  }
 for(i=0;i<n;i++)
  {
      sum+=dp[i];
      if(maxi<sum)
       {
           maxi=sum;
       }
      else if(sum<0)
       sum=0;
  }
 //if(maxi) 
 cout<<maxi+c<<endl; 
}