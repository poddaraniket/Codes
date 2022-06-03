int row[8]={0,1,1,1,0,-1,-1,-1};
    int col[8]={1,1,0,-1,-1,-1,0,1};
    void dfs(vector<vector<char>>& grid,int r,int c,vector<vector<bool>> &vis){
        vis[r][c]=true;
        for(int i=0;i<8;i++){
            int x=row[i]+r;
            int y=col[i]+c;
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
                if(!vis[x][y] && grid[x][y]=='1'){
                    dfs(grid,x,y,vis);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        // for(int i=0;i<grid.size();i++)
        // {
        //     for(int j=0;j<grid[0].size();j++)
        //      {
        //         vis[i][j]=false; 
        //      }
        // }
        
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
             {
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,vis);
                } 
             }
        }
        return count;
    }