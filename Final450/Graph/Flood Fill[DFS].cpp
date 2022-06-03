int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};
    void floodFillUtil(vector<vector<int>>& image, int sr, int sc, int newColor,int oldColor,vector<vector<bool>> vis){
        vis[sr][sc]=true;
        image[sr][sc]=newColor;
        for(int i=0;i<4;i++){
            int x=sr+row[i];
            int y=sc+col[i];
            if(x>=0 && x<image.size() && y>=0 && y<image[0].size()){
                if(!vis[x][y] && image[x][y]==oldColor)
                  floodFillUtil(image,x,y,newColor,oldColor,vis);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int oldColor=image[sr][sc];
        floodFillUtil(image,sr,sc,newColor,oldColor,vis);
        return image;
    }