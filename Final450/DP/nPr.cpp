//nPr = r * n-1Pr-1 + n-1Pr

#include <bits/stdc++.h>
using namespace std;

//P(n, k) = P(n-1, k) + k* P(n-1, k-1)  

int permutationCoeff(int n,int k){
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(j>=i)
             dp[i][j]=dp[i][j-1]+i*dp[i-1][j-1];
        }
    }
    return dp[k][n];
}

int main()
{
    int n = 10, k = 3;
    printf("Value of P(%d, %d) is %d ",n, k, permutationCoeff(n, k));
    return 0;
}