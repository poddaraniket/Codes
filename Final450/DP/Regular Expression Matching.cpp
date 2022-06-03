#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str,patt;
    cin>>str;
    cin>>patt;
    int n=patt.length();
    int m=str.length();
    //cout<<n<<" "<<m<<endl;
    bool dp[n+1][m+1];
    dp[0][0]=true;
    for(int i=1;i<=m;i++)
     dp[0][i]=false;
    for(int i=1;i<=n;i++)
     {
        if(patt[i-1]=='*')
         dp[i][0]=dp[i-2][0];
        else
         dp[i][0]=false;
     }
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++)
         {
            if(patt[i-1]=='.')
             dp[i][j]=dp[i-1][j-1];
            else if(patt[i-1]=='*')
             {
                dp[i][j]=dp[i-2][j]; 
                if(patt[i-2]==str[j-1] || patt[i-2]=='.')
                 {
                    dp[i][j]=dp[i][j] | dp[i][j-1]; 
                 }
             }
            else
             {
                if(patt[i-1]==str[j-1])
                 dp[i][j]=dp[i-1][j-1];
                else
                 dp[i][j]=false;
             }
            // cout<<dp[i][j]<<" "; 
         }
        // cout<<endl; 
    }
    if(dp[n][m]==0)
     cout<<"false"<<endl;
    else 
    cout<<"true"<<endl;
}