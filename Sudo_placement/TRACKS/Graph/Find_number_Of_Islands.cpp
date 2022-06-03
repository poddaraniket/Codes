#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
map<int,int> mp;
bool vis[101][101];

void dfs(int x,int y,vector<int> A[], int N, int M)
{
    vis[x][y]=true; 
    for(int i=x-1;i<=x+1;i++)
     {
        for(int j=y-1;j<=y+1;j++)
         {
            if(i>=0 && j>=0 && i<=N-1 && j<=M-1)
              {
                if(!(i==x && j==y) && A[i][j]==1 && vis[i][j]==false) 
                  dfs(i,j,A,N,M);
              }
         }
     }
     
}

int findIslands(vector<int> A[], int N, int M) {
    // Your code here
    memset(vis,false,sizeof(vis));
    int count=0;
    for(int i=0;i<N;i++)
     {
        for(int j=0;j<M;j++)
         {
            if(A[i][j]==1 && vis[i][j]==false)
            {
               count++; 
               dfs(i,j,A,N,M);
            }
         }
     }
    return count; 
}
