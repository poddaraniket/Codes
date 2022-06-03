#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int dp[s.length()+1]={0};
    dp[0]=1;
    int n=s.length();
    int loc[26]={-1};
    for(int i=1;i<n;i++)
     {
        dp[i]=dp[i-1]*2;
        if(loc[s[i]-'a']!=-1)
         {
            dp[i]-=dp[loc[s[i]-'a']-1];
            loc[s[i]-'a']=i;
         }
     }
    cout<<dp[n]<<endl; 
}