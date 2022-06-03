#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    bool dp[n][n];
    for(int i=0;i<n;i++)
     dp[i][i]=true;
    int c=n; 
    for(int gap=2;gap<=n;gap++)
     {
        for(int i=0;i<n-gap+1;i++)
         {
            int j=i+gap-1;
            if(s[i]==s[j] && gap==2)
             {
                dp[i][j]=true;
                c++;
             }
            else if(s[i]==s[j])
             {
                dp[i][j]=dp[i+1][j-1];
                if(dp[i][j])
                 c++;
             }
            else
             dp[i][j]=false;
         }
     }
    cout<<c<<endl; 
}