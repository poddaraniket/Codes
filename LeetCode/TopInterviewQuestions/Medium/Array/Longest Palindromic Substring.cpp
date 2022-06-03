//O(n^2)
#include<bits/stdc++.h>
 
using namespace std;
 
int longestPalSubstr(string str)
{
    int n=str.length();
    bool dp[n][n]={false};
    for(int i=0;i<n;i++)
     {
        dp[i][i]=true; 
     }
    int maxLength=1; 
    for(int k=2;k<=n;k++)
     {
        for(int i=0;i<=n-k;i++)
         {
            int j=i+k-1;
            if(str[i]==str[j])
             {
                if(k==2)
                 dp[i][j]=true;
                else
                 {
                    dp[i][j]=dp[i+1][j-1]; 
                 }
             }
            else
             {
                dp[i][j]=false; 
             }
            if(dp[i][j])
             maxLength=max(maxLength,j-i+1);
         }
     }
    return maxLength; 
}
 
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str);
    return 0;
}