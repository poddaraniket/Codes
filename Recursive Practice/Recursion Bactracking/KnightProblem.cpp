/*
chess[r][c]=move+1;
printKnightsTour(chess,n,r,c,upcomingMove+1);
printKnightsTour(chess,n,r,c,upcomingMove+1);
printKnightsTour(chess,n,r,c,upcomingMove+1);         chess[r][c]=move+1;    
printKnightsTour(chess,n,r,c,upcomingMove+1);   ->    for(k=0;k<8;k++){
printKnightsTour(chess,n,r,c,upcomingMove+1);           int x=r+dir[k][0];        
printKnightsTour(chess,n,r,c,upcomingMove+1);           int y=c+dir[k][1];    
printKnightsTour(chess,n,r,c,upcomingMove+1);           printKnightsTour(chess,n,x,y,upcomingMove+1);
printKnightsTour(chess,n,r,c,upcomingMove+1);         }
chess[r][c]=0;                                        chess[r][c]=0;  
*/



#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int dir[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

void printKnightsTour(vector<vector<int>> chess, int n, int r, int c, int upcomingMove) {
  //write your code here
  if(r<0 || c<0 || r>=chess.size() || c>=chess.size() || chess[r][c]>0)
   return;
  if(upcomingMove==chess.size()*chess.size()){
    chess[r][c]=upcomingMove;
    display(chess);
    chess[r][c]=0;
    return;
  } 
  chess[r][c]=upcomingMove;
  for(int k=0;k<8;k++){
    int x=r+dir[k][0];        
    int y=c+dir[k][1];   
    printKnightsTour(chess,n,x,y,upcomingMove+1);
  }
  chess[r][c]=0;

}

int main() {
    int n;
    cin>>n;
    int r,c;
    cin>>r>>c;
    vector<vector<int>> chess(n,vector<int>(n,0));
    printKnightsTour(chess,n,r,c,1);
}