class Solution {
public:
    
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& dist)
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool> (m, false));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                 {
                   q.push({i,j}); 
                   vis[i][j]=true;
                   dist[i][j]=0; 
                 }
            }
        }
        int x_dir[]={-1,+1,0,0};
        int y_dir[]={0,0,+1,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=r+x_dir[i];
                int y=c+y_dir[i];
                if(x>=0 && y>=0 && x<mat.size() && y<mat[0].size())
                {
                    if(!vis[x][y] && dist[r][c]+1<dist[x][y]){
                         q.push({x,y});
                         vis[x][y]=true;
                         dist[x][y]=dist[r][c]+1;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        bfs(mat,dist);
        return dist;
    }
};