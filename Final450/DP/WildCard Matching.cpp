#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str,patt;
    cin>>str>>patt;
    int n=patt.length();
    int m=str.length();
    bool dp[n+1][m+1];
    dp[n][m]=true;
    // blank in patt does it match with any of the char in string [ans->no]
    for(int j=m-1;j>=0;j--)
     {
        dp[n][j]=false; 
     }
    for(int i=n-1;i>=0;i--)
     {
        if(patt[i]=='*')
         dp[i][m]=dp[i+1][m];
        else
         dp[i][m]=false;
     }
    for(int i=n-1;i>=0;i--)
     {
        for(int j=m-1;j>=0;j--)
         {
            if(patt[i]=='?')
             dp[i][j]=dp[i+1][j+1];
            else if(patt[i]=='*')
             dp[i][j]=dp[i+1][j]||dp[i][j+1];
            else
             {
                if(patt[i]==str[j])
                 dp[i][j]=dp[i+1][j+1];
                else
                 dp[i][j]=false;
             }
         }
     }
    if(dp[0][0]==0) 
        cout<<"false"<<endl;
    else
        cout<<"true"<<endl;
}