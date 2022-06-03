class Solution {
public:
    
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isSafe(int r,int c,int n,int m){
        if(r<0 || c<0 || r>=n || c>=m)
            return false;
        return true;
    }
    
    bool possible(vector<vector<char>>& board,int row,int col, string word,int index){
        
        if(index==word.length()){
            return true;
        }
        
        for(int k=0;k<4;k++){
            int r=dir[k][0]+row;
            int c=dir[k][1]+col;
            if(isSafe(r,c,board.size(),board[0].size())){
                if(board[r][c]==word[index]){
                    //do
                    char t=board[r][c];
                    board[r][c]='&';
                    //recur
                    if(possible(board,r,c,word,index+1))
                        return true;
                    //undo
                    board[r][c]=t;
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    board[i][j]='&';
                    if(possible(board,i,j,word,1))
                        return true;
                    board[i][j]=word[0];
                }
            }
        }
       return false; 
    }
};