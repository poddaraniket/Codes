class Solution {
public:
    int n,m;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isSafe(int x,int y)
    {
        if(x>=0 && y>=0 && x<n && y<m)
            return true;
        return false;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, int oldColor,int newColor){
        //vis[row][col]=true;
        grid[row][col]*=-1;
        int count=0;
        for(int k=0;k<4;k++)
        {
            int x=row+dir[k][0];
            int y=col+dir[k][1];
            if(isSafe(x,y) && abs(grid[x][y])==oldColor)
            {
                count++;
                if(grid[x][y]==oldColor)
                  dfs(grid,x,y,oldColor,newColor);   
            }
        }
        if(count==4)
                 grid[row][col]*=-1;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n=grid.size();
        m=grid[0].size();
        int oldColor=grid[row][col];
        int newColor=color;
        //vector<vector<int>> count(n,vector<int> (m,0));
        dfs(grid,row,col,oldColor,newColor);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)
                    grid[i][j]=newColor;
            }
        }
        return grid;
    }
};