// last waley ko chor do wen we are in secind last step and last step theek hai to phir hum uss second last step sai 
//baki other direction dhoondtey hai aur na miley to usko theek karke ek step piche jatey hai aur waha sai try kartey 
//hai ki koi aur new path mil jaye   

void dfs(vector<vector<int>> &m, int r,int c,int n,vector<string> &ans,string path)
    {
        //cout<<r<<" "<<path<<endl;
       
        if(r==n-1 && c==n-1)
         {
             //cout<<path<<endl;
             ans.push_back(path);
             return;
         }
        m[r][c]=-1; 
        if(r-1>=0 && m[r-1][c]==1)
         dfs(m,r-1,c,n,ans,path+"U");
        if(r+1<n && m[r+1][c]==1)
         dfs(m,r+1,c,n,ans,path+"D");
        if(c-1>=0 && m[r][c-1]==1)
         dfs(m,r,c-1,n,ans,path+"L");
        if(c+1<n && m[r][c+1]==1)
         dfs(m,r,c+1,n,ans,path+"R");
        // BackTracking (Always leave the dest cond untouched) [Jo bigara tha usk theek kar do]
        if(m[r][c]==-1)
         m[r][c]=1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==1)
         dfs(m,0,0,n,ans,"");
        sort(ans.begin(),ans.end()); 
        return ans;
    }