#include <bits/stdc++.h>
#define bool int
#define R 6
#define C 5
using namespace std;
 
 
void printMaxSubSquare(bool M[R][C])
{
    int dp[R][C];
    int max_X=0,max_Y=0,maxi=0;
    for(int i=0;i<R;i++)
     {
        dp[i][0]=M[i][0];
        if(maxi<dp[i][0]){
         maxi=1;  
         max_X=i;
         max_Y=0;
        }
     }
    for(int i=0;i<C;i++)
     {
        dp[0][i]=M[0][i];
        if(maxi<dp[0][i])
         {
            maxi=1;
            max_X=0;
            max_Y=i;
         }
     }
    for(int i=1;i<R;i++)
     {
         for(int j=1;j<C;j++)
          {
             if(M[i][j]==1) 
              dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1; 
             else
              dp[i][j]=0;
             if(maxi<dp[i][j])
              {
                maxi=dp[i][j];
                max_X=i;
                max_Y=j;
              }
          }
     }
    for(int i=max_X;i>max_X-maxi;i--)
     {
        for(int j=max_Y;j>max_Y-maxi;j--)
         {
            cout<<"1"<<" "; 
         }
        cout<<endl; 
     }
}

int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 0, 1},
                    {0, 0, 0, 0, 0}};
                     
    printMaxSubSquare(M);
}
 