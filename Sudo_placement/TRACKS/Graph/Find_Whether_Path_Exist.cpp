#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

bool is_possible(vector<vector<int>> &a, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(MAX, vector<int>(MAX, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        cout << is_possible(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++


// M : input matrix
// N : size of the matrix
bool vis[MAX][MAX];
int block[MAX][MAX];

void dfs(vector<vector<int>> &M,int N,int i,int j)
{
    if(i<0 || i>=N || j<0 || j>=N || vis[i][j]==true || block[i][j]==1)
     return;
    vis[i][j]=true;
    block[i][j]=1;
    if(i>0)
     {
        dfs(M,N,i-1,j); 
     }
    if(i<N-1)
     {
        dfs(M,N,i+1,j); 
     }
    if(j>0)
     {
        dfs(M,N,i,j-1); 
     }
    if(j<N-1)
     {
        dfs(M,N,i,j+1); 
     }
}

bool is_possible(vector<vector<int>> &M, int N) {
   int row_d=-1,col_d=-1,row_s=-1,col_s=-1; 
   memset(vis,false,sizeof(vis));
   memset(block,0,sizeof(block));
   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
         {
            if(M[i][j]==0)
             {
                block[i][j]=1;
                vis[i][j]=true;
             }
            else if(M[i][j]==1)
             {
                row_s=i;
                col_s=j;
             } 
            else if(M[i][j]==2)
             {
                 row_d=i;
                 col_d=j;
             }
         }
    }
   if(row_d!=-1 && row_s!=-1)    
     dfs(M,N,row_s,col_s);
   if(vis[row_d][col_d])
    return true;
   return false;    
}
