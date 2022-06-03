//O(N*M)

// Mark all the O's connected to boundary with * so we know ath end that once left as O are to 
// surrounded and need to be convertd to X rest to O

class Solution {
public:
    
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isSafe(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    }
    
    void dfs(vector<vector<char>>& board,int i,int j,int n,int m){
        board[i][j]='*';
        for(int k=0;k<4;k++){
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(isSafe(x,y,n,m) && board[x][y]=='O'){
                dfs(board,x,y,n,m);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        // convert all boundar conneted O's to *
        
        //First ROW
        for(int j=0;j<m;j++){
            if(board[0][j]=='O')
                dfs(board,0,j,n,m);
        }
        
        
        // Last Row
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O')
                dfs(board,n-1,j,n,m);
        }
        
        // First Column
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(board,i,0,n,m);
        }
        
        // Last Column
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O')
                dfs(board,i,m-1,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='*')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};