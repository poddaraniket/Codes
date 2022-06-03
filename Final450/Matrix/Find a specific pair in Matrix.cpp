#include <bits/stdc++.h>
using namespace std;

#define N 5

int findMaxValue(int mat[][N]){
    int dp[N][N];
    for(int i=0;i<N;i++)
     dp[i][N-1]=0;
    for(int i=0;i<N;i++)
     dp[N-1][i]=0; 
    for(int i=N-2;i>=0;i--)
     {
        for(int j=N-2;j>=0;j--)
        {
            dp[i][j]=max(max(dp[i+1][j],dp[i][j+1]),mat[i+1][j+1]);
        }
     }
    // for(int i=0;i<N;i++)
    //  {
    //      for(int j=0;j<N;j++)
    //       {
    //           cout<<dp[i][j]<<" ";
    //       }
    //      cout<<endl; 
    //  }
    int maxi=0; 
    for(int i=0;i<N-1;i++)
     {
        for(int j=0;j<N-1;j++)
         {
            maxi=max(dp[i][j]-mat[i][j],maxi); 
         }
     }
    return maxi;
}


int main() {
	int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { 0, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 0, -5, 1 }
            };
    cout << "Maximum Value is "
        << findMaxValue(mat); 
	return 0;
}
