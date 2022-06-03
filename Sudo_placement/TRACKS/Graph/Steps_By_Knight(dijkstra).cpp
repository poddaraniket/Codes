// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main() {
    // size of square board
    int t;
    cin >> t;
    while (t--) {
        int N;
        int a, b, c, d;
        cin >> N;
        cin >> a >> b;
        cin >> c >> d;
        int knightPos[] = {a, b};
        int targetPos[] = {c, d};
        cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size

bool isSafe(int i,int j,int n)
{
    if(i<0 || j<0 || i>n || j>n)
     return false;
    return true; 
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    // code here
    vector<vector<bool>> vis(N+1,vector<bool> (N+1, false));
    int dist[N+1][N+1];
    for(int i=0;i<=N;i++)
     {
        for(int j=0;j<=N;j++)
          dist[i][j]=INT_MAX;
     }
    queue<pair<int,int>> q;
    q.push({knightPos[0],knightPos[1]});
    dist[knightPos[0]][knightPos[1]]=0;
    int x_dir[]={-1, -1, -2, -2, +1, +1, +2, +2};
    int y_dir[]={-2, +2, -1, +1, -2, +2, -1, +1};
    while(!q.empty())
     {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==targetPos[0] && y==targetPos[1])
         return dist[x][y];
        vis[x][y]=true;
        for(int k=0;k<8;k++)
         {
            int x1=x+x_dir[k];
            int y1=y+y_dir[k];
            if(isSafe(x1,y1,N))
             {
                if(vis[x1][y1]==false && dist[x1][y1]>dist[x][y]+1 )
                 {
                    dist[x1][y1]=dist[x][y]+1;
                    q.push({x1,y1});
                 }
             }
         }
     }
}