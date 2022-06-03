int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};
    char dir[4]={'U','R','D','L'};
    void findPathUtil(vector<vector<int>> &m, int n,vector<vector<bool>> &vis,string path,int r,int c,vector<string> &res){
        if(r==n-1 && c==n-1){
         res.push_back(path);
         return;    
        }
        vis[r][c]=true;
        for(int k=0;k<4;k++){
            int x=row[k]+r;
            int y=col[k]+c;
            if(x>=0 && x<n && y>=0 && y<n){
                if(!vis[x][y] && m[x][y]==1)
                 {
                     findPathUtil(m,n,vis,path+dir[k],x,y,res);
                 }
            }
        }
        vis[r][c]=false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<string> res;
        if(m[0][0]==0){
            res.push_back("-1");
        }
        else{
        findPathUtil(m,n,vis,"",0,0,res);
        sort(res.begin(),res.end());
        }
        return res;
    }