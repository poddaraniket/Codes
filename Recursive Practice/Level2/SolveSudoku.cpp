//O(9^(n*n))

#include<bits/stdc++.h>

using namespace std;

void display(vector<vector<int>> board){
    for(int i = 0; i < board.size(); i++){
      for(int j = 0; j < board[0].size(); j++){
        cout<<board[i][j]<<" ";
      }
      cout<<endl;
    }
}


bool isSafe(int i,int j,int val,vector<vector<int>> board){
    //row
    for(int k=0;k<board[0].size();k++){
        if(board[i][k]==val)
         return false;
    }
    //column
    for(int k=0;k<board[0].size();k++){
        if(board[k][j]==val)
         return false;
    }
    //submatrix
    int startRow=i-(i%3);
    int startCol=j-(j%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i+startRow][j+startCol]==val)
              return false;
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> board, int i, int j) {
    // write your code here
    int m=board.size();
    int n=board[0].size();
    // cout<<i<<" "<<j<<endl;
    int ni=0,nj=0;
    if(i==m){
        display(board);
        return;
    }
    if(j==n-1){
        nj=0;
        ni=i+1;
    }else{
        nj=j+1;
        ni=i;
    }
    if(board[i][j]>0){
        solveSudoku(board, ni, nj);
    }else{
       for(int k=1;k<=9;k++){
            if(isSafe(i,j,k,board)){
                board[i][j]=k;
                solveSudoku(board, ni, nj);
                board[i][j]=0;
            }
        } 
    }
}

int main(){
    vector<vector<int>> board(9,vector<int>(9));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
          cin>>board[i][j];
      }
    }
    solveSudoku(board, 0, 0);
}
