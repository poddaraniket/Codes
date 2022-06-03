//O(N*M)

class Solution {
public:
    
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isSafe(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    }
    
    void dfs(int i,int j,int m,int n,vector<vector<char>> &grid){
        // vis[node] = 1;
        grid[i][j] = '0';
        for(int idx=0;idx<4; idx++){
            int next_i = i+dir[idx][0];
            int next_j = j+dir[idx][1];
            if(isSafe(next_i,next_j,m,n) && grid[next_i][next_j] == '1'){
                dfs(next_i,next_j,m,n,grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> vis(m,vector<int> (n,0));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    cnt += 1;
                    dfs(i,j,m,n,grid);
                }
            }
        }
        return cnt;
    }
};