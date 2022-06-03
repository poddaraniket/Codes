// 2 means 0->1 ; -2 means 1->0

class Solution {
public:
    
    int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    
    bool isValid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    } 
    
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count=0;
                for(int k=0;k<8;k++){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(isValid(x,y,board.size(),board[0].size()) && (board[x][y]==1 || board[x][y]==-2))
                        count++;
                  }
                if(board[i][j]==1 && (count<2 || count>3)){
                    board[i][j]=-2;
                }
                if(board[i][j]==0 && count==3){
                    board[i][j]=2;
                }
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==-2)
                    board[i][j]=0;
                if(board[i][j]==2)
                    board[i][j]=1;
            }
        }
    }
};