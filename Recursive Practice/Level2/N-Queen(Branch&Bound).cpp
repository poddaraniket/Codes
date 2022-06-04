/*

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

Almost lik above bt here the brnches are more blocked bcoz once a queen is placed 
in its row it blocks its column and its diagonals as well so we have to filter 
less for next queen in the next row


*/


*/



#include<bits/stdc++.h>
using namespace std;

vector<bool> column,leftDiagonal,rightDiagonal;

bool isSafe(int row,int col,int leftDiagonalIndex,int rightDiagonalIndex){
    if(column[col] || leftDiagonal[leftDiagonalIndex] || rightDiagonal[rightDiagonalIndex]){
        return false;
    }
    return true;
}

void printNQueens(vector<vector<int>> chess, string qsf, int currRow){
    int totalRows=chess.size();
    if(currRow>=totalRows){
        cout<<qsf<<"."<<endl;
        return;
    }
    
    int totalCols=totalRows;
    for(int col=0;col<totalCols;col++){
        int leftIndexDiagonal=currRow-col+(totalCols-1);
        int rightIndexDiagonal=currRow+col;
        if(isSafe(currRow,col,leftIndexDiagonal,rightIndexDiagonal)){
            chess[currRow][col]=1;
            column[col]=true;
            leftDiagonal[leftIndexDiagonal]=true;
            rightDiagonal[rightIndexDiagonal]=true;
            char r=(char)currRow+48;
            char c=(char)col+48;
            string index="";
            index+=r;
            index+='-';
            index+=c;
            printNQueens(chess,qsf+index+", ",currRow+1);
            column[col]=false;
            leftDiagonal[leftIndexDiagonal]=false;
            rightDiagonal[rightIndexDiagonal]=false;
            chess[currRow][col]=0;
        }
    }
}

int main() {
  int n;
  cin >> n;
  column=vector<bool> (n,false);
  leftDiagonal=vector<bool> (2*n-1,false);
  rightDiagonal=vector<bool> (2*n-1,false);
  vector<vector<int>> chess(n, vector<int> (n,0));

  printNQueens(chess, "", 0);

}