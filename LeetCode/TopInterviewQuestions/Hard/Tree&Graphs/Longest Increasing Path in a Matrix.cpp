//O(N*M)

class Solution {
public:
    
    vector<vector<int>> dp;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
    bool isSafe(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    }
    
    int dfs(vector<vector<int>>& matrix,int i,int j,int n,int m){
        if(dp[i][j])
            return dp[i][j];
        // check for every point so that point itself is 1 point
        int ans=1;
        for(int k=0;k<4;k++){
            int x=dir[k][0]+i;
            int y=dir[k][1]+j;
            if(isSafe(x,y,n,m)){
                if(matrix[i][j]<matrix[x][y])
                    // max path for that i,j among all paths
                    ans=max(ans,1+dfs(matrix,x,y,n,m));
            }
        }
        dp[i][j]=ans;
        return dp[i][j]; // store that max path in dp matrix
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0)
            return 0;
        dp=vector<vector<int>>(n,vector<int>(m,0));
        int res=0;
        for(int i=0;i<n;i++){
            {
                for(int j=0;j<m;j++){
                    res=max(res,dfs(matrix,i,j,n,m));
                }
            }
        }
        return res;
    }
};