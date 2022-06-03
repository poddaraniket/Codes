#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends


/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   A[][]: 2D matrix from input
*/
bool vis[SIZE][SIZE];

int dfs(int x,int y,int A[SIZE][SIZE],int n,int m,int &count)
{
    vis[x][y]=true;
    for(int i=x-1;i<=x+1;i++)
     {
        for(int j=y-1;j<=y+1;j++)
         {
            if(i>=0 && j>=0 && i<n && j<m)
             {
                if(!(i==x && j==y) && A[i][j]==1 && vis[i][j]==false)
                {
                 count++;
                 dfs(i,j,A,n,m,count);
                }
             }
         }
     }
    return count; 
}

int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{
    // Your code here
    int maxi=0;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<N;i++)
     {
        for(int j=0;j<M;j++)
         {
            if(A[i][j]==1 && vis[i][j]==false) 
             {
               int count=1;     
               maxi=max(maxi,dfs(i,j,A,N,M,count)); 
             }
         }
     }
    return maxi; 
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}  // } Driver Code Ends