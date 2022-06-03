#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int len=s.size();
  int dp[len+1];
  dp[len]=0;
  for(int i=len-1;i>=0;i--)
   {
     int t=s[i]-'0';
     if(t%2==0)
      dp[i]=dp[i+1]+1;
     else
      dp[i]=dp[i+1]; 
   }
  for(int i=0;i<len;i++)
   cout<<dp[i]<<" ";
  cout<<endl;  
}