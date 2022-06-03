#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
     {
       int n,m;
    cin>>n;
    int val[2]={1,2}; 
    m=2;
    //for(int i=0;i<)
    int dp[n+1][m];
    for(int i=0;i<m;i++)
     dp[0][i]=1;
  
    //we did X+Y bcoz when we do stuffs like dp[n-a]+dp[n-b] we include repeated ways with diff pattern
    // x means to include the jth coin, digit in sum 
    //y will not include and in that we add no. of digits that formed that value without jth coin/digit bt here we just add adjacent one bcoz that has all possible unique versions
    // if it would have said order doesn't matter den we would have done dp[n-a]+dp[n-b] stuffs here

    for(int i=1;i<=n;i++)
     {
       for(int j=0;j<m;j++)
        {
            int x=0,y=0;
            if(i>=val[j])
             {
                 x=dp[i-val[j]][j];
             }
            if(j>=1)
             y=dp[i][j-1];
            dp[i][j]=x+y; 
        }
     }
    cout<<dp[n][m-1]<<endl; 
     }
    return 0;
}
