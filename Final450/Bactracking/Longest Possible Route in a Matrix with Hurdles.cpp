//vector<vector<int>> vec( n , vector<int> (m, 0));
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 10

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool isSafeAndReachable(int mat[R][C],int x,int y)
 {
    if(x>=0 && y>=0 && x<R && y<C && mat[x][y]>0)
     return true;
    return false; 
 }

void findLongestPathUtil(int mat[R][C],int srcX,int srcY,int destX,int destY,vector<vector<int>> &dist)
{
    //cout<<srcX<<" "<<srcY<<endl;
    if(srcX==destX && srcY==destY)
     {
        return; 
     }
    mat[srcX][srcY]*=-1;
    for(int k=0;k<4;k++)
     {
        int x=dir[k][0]+srcX;
        int y=dir[k][1]+srcY;
        if(isSafeAndReachable(mat,x,y) && dist[x][y]<dist[srcX][srcY]+1)
         {
            dist[x][y]=dist[srcX][srcY]+1;
            findLongestPathUtil(mat,x,y,destX,destY,dist);
         }
     }
    mat[srcX][srcY]*=-1; 
}

void findLongestPath(int mat[R][C],int srcX,int srcY,int destX,int destY)
{
    vector<vector<int>> dis(3,vector<int> (10,0));
    findLongestPathUtil(mat,srcX,srcY,destX,destY,dis);
    cout<<dis[destX][destY]<<endl;
}

int main()
{
    // input matrix with hurdles shown with number 0
    int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
 
    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);
 
    return 0;
}