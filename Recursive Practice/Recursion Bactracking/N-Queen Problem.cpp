/*
we make the grid 1 when we place the queen there and make it 0 again when we remove it from there 

// n -> row n->queen (place each queen in each row)

(x) -> nt safe from that row and column as som queen that is already placed might kill u
(.) -> safe box                    
                                  (x)(x)(x)(x)   (Not safe anywhere -> come back to row 1 and remove the queen from there and ry finding next safe place for her in that row itself)
                                    \ \  / /
                                        2     (placing in row 2)
                                (x)(x) (.)    (safe to place in col 2 of row 1)
                                0\ 1\  2/ 3/
                                      1       (placing in row 1)
                                     (.)     
                                      1 1  1  1    (safe to place in col 0 of row 0)
                                      0\1\2/3/ cols
                                         0     row (placing in row 0)

*/



#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,vector<vector<int>> chess){
    //row safe
    for(int i=0;i<x;i++){
        if(chess[i][y]==1)
         return false;
    }
    // left diagonal
    for(int i=x-1,j=y-1 ; i>=0 && j>=0 ;i--,j--){
        if(chess[i][j]==1)
         return false;
    }
    
    // right diagonal
    for(int i=x-1,j=y+1 ; i>=0 && j<chess[0].size() ;i--,j++){
        if(chess[i][j]==1)
         return false;
    }
    return true;
}

void printNQueens(vector<vector<int>> chess, string qsf, int row) {
  //write your code here
  if(row>=chess.size()){
      cout<<qsf<<"."<<endl;
      return;
  }
  for(int col=0;col<chess.size();col++){
      if(isSafe(row,col,chess)){
          chess[row][col]=1;
          char r=(char)row+48;
          char c=(char)col+48;
          string index="";
          index+=r;
          index+='-';
          index+=c;
          printNQueens(chess,qsf+index+", ",row+1);
          chess[row][col]=0;
      }
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n,0));

  printNQueens(chess, "", 0);

}