// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int shortest(vector<vector<int> > &grid ,int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > grid(n);

        for (int i = 0; i < n; i++) 
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++) 
            {
                cin >> grid[i][j];
            }
        }
        
        cout << shortest(grid,n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// grid : given n*n grid 
// n : size of the square grid

#define pll pair<int,pair<int,int>>

bool isSafe(int x,int y,int n)
{
    if(x<0 || y<0 || x>=n || y>=n)
     return false;
    return true; 
}

int dijkstra(vector<vector<int>>&grid,int x,int y,int n)
{
    int i,j;
    bool vis[n][n];
    memset(vis,false,sizeof(vis));
    //cout<<vis[1][1]<<endl;
    long long int dis[n][n];
    for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
           dis[i][j]=INT_MAX;
     }
    //cout<<dis[1][1]<<endl;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({grid[x][y],{x,y}});
    dis[x][y]=grid[x][y];
    int x_dist[]={0,0,-1,+1};
    int y_dist[]={-1,+1,0,0};
    while(!pq.empty())
    {
        x=pq.top().second.first;
        y=pq.top().second.second;
        pq.pop();
        if(vis[x][y]==true)
         continue;
        vis[x][y]=true; 
        for(int k=0;k<4;k++)
         {
             int x1=x+x_dist[k];
             int y1=y+y_dist[k];
             if(isSafe(x1,y1,n))
             {
                 if(vis[x1][y1]==false && dis[x][y]!=INT_MAX && dis[x1][y1]>grid[x1][y1]+dis[x][y])
                 {
                    dis[x1][y1]=grid[x1][y1]+dis[x][y];
                    pq.push({dis[x1][y1],{x1,y1}});
                 }
             }
         }
    }
   return dis[n-1][n-1];    
}

int shortest(vector<vector<int> > &grid, int n) {
    // Your code goes here
    return dijkstra(grid,0,0,n);
}