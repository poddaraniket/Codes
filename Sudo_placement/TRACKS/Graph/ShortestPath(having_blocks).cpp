#include <bits/stdc++.h>
using namespace std;

int n,m;
int x_dir[]={-1,0,+1,0};
int y_dir[]={0,+1,0,-1};
int block[20][20],mat[20][20],dist[20][20];
bool vis[20][20];

bool isSafe(int n,int m,int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || block[i][j]==1)
     return false;
    return true; 
}

int dijkstra(int destX,int destY)
{
    if(block[0][0]==1 || block[destX][destY]==1)
      return -1;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    dist[0][0]=0;
    pq.push({0,{0,0}});
    vis[0][0]=true;
    while(!pq.empty())
     {
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        if(x==destX && y==destY)
          return dist[x][y];
        for(int i=0;i<4;i++)
         {
            int x1=x+x_dir[i];
            int y1=y+y_dir[i];
            if(isSafe(n,m,x1,y1))
             {
                if(dist[x][y]!=INT_MAX && dist[x1][y1]>dist[x][y]+1 && vis[x1][y1]==false)
                 {
                    //cout<<x1<<" "<<y1<<endl; 
                    dist[x1][y1]=dist[x][y]+1;
                    vis[x1][y1]=true;
                    pq.push({dist[x1][y1],{x1,y1}});
                 }
             }
          }
     }
    return -1; 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
     {
        cin>>n>>m;
        for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
             {
                cin>>mat[i][j];
                if(mat[i][j]==1)
                 block[i][j]=0;
                else
                 block[i][j]=1;
                dist[i][j]=INT_MAX; 
                vis[i][j]=false;
             }
         }
        int destX,destY; 
        cin>>destX>>destY;
        int ans=dijkstra(destX,destY);
        cout<<ans<<endl;
     }
}