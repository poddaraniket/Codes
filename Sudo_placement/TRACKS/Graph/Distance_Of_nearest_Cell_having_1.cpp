#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

vector <vector <int> > nearest(vector<vector<int>> &arr, int row, int col);
int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        print (nearest(graph, row, col), row, col);
    }

    return 0;
}
// } Driver Code Ends


/*  Function to find the distance of nearest cell having 1

*   mat: The input matrix of 0s and 1s
*   N, M: rows and cols in given matrix
*   Return the resultant matrix of size (N x M) representing the nearest distance 1 from each cell
*/

bool isSafe(int x,int y,int r,int c)
{
    if(x<0 || y<0 || x>=r || y>=c)
     return false;
    return true; 
}

void BFS(vector<vector<int>> &mat, int N, int M,vector<vector<int>> &dist)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(N,vector<bool> (M, false));
    for(int i=0;i<N;i++)
     {
        for(int j=0;j<M;j++)
         {
            if(mat[i][j]==1)
             {
                q.push({i,j});
                vis[i][j]=true;
                dist[i][j]=0;
             }
            else
             dist[i][j]=INT_MAX;
         }
     }
    int x_dir[]={-1,+1,0,0};
    int y_dir[]={0,0,+1,-1};
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
         {
            int x1=x+x_dir[i];
            int y1=y+y_dir[i];
            if(isSafe(x1,y1,N,M) && !(vis[x1][y1]))
             {
                q.push({x1,y1});
                vis[x1][y1]=true;
                dist[x1][y1]=min(dist[x1][y1],1+dist[x][y]);
             }
         }
    }
}

vector <vector <int> > nearest(vector<vector<int>> &mat, int N, int M) {

    // Your code here
    vector<vector<int>> dist(N,vector<int> (M,0));
    BFS(mat,N,M,dist);
    return dist;
}