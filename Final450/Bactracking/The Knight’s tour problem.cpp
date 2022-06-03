//vector<vector<int>> vec( n , vector<int> (m, 0));
#include <bits/stdc++.h>
using namespace std;

#define N 8

int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

bool isSafe(vector<vector<int>> &chess,int x,int y)
{
    if(x>=0 && y>=0 && x<N && y<N && chess[x][y]==-1)
     return true;
    return false; 
}

int solveKTUtil(vector<vector<int>> &chess,int x,int y,int move)
{
    if(move==(N*N))
     return 1;
    for(int k=0;k<8;k++)
     {
        int x_dir=x+dir[k][0];
        int y_dir=y+dir[k][1];
        if(isSafe(chess,x_dir,y_dir))
         {
            chess[x_dir][y_dir]=move;
            if(solveKTUtil(chess,x_dir,y_dir,move+1)==1)
             return 1;
            else
             chess[x_dir][y_dir]=-1;
         }
     }
    return 0; 
}

void solveKT(){
    vector<vector<int>> chess(N,vector<int>(N,-1));
    chess[0][0]=0;
    solveKTUtil(chess,0,0,1);
    for(int i=0;i<N;i++)
     {
         for(int j=0;j<N;j++)
          {
             cout<<chess[i][j]<<" ";  
          }
         cout<<endl; 
     }
}

int main()
{
      // Function Call
    solveKT();
    return 0;
