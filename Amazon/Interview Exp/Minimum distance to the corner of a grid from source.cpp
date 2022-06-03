#include <bits/stdc++.h>
using namespace std;

#define row 5
#define col 5
 
int minDistance[row + 1][col + 1], vis[row + 1][col + 1];

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool isValid(int grid[][col], int i, int j)
{
    if (i < 0 || j < 0
        || j >= col || i >= row
        || grid[i][j] || vis[i][j])
        return false;
 
    return true;
}
 

int minDistanceUtil(int grid[][col],int sourceRow,int sourceCol){
    if(sourceRow==0 || sourceRow==row-1 || sourceCol==0 || sourceCol==col-1)
      return -1;
    int minDistanceFromSource=row*col;  
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            minDistance[i][j] = row * col;
        }
    }
    minDistance[sourceRow][sourceCol]=0;
    vis[sourceRow][sourceCol]=1;
    queue<pair<int,int>> q;
    q.push({sourceRow,sourceCol});
    while(!q.empty()){
        pair<int,int> cell=q.front();
        q.pop();
        int cellRow = cell.first;
        int cellCol = cell.second;
        for(int k=0;k<4;k++){
            int x=cellRow+dir[k][0];
            int y=cellCol+dir[k][1];
            if(isValid(grid,x,y)){
                q.push({x,y});
                minDistance[x][y]=min(minDistance[x][y],minDistance[cellRow][cellCol]+1);
                vis[x][y]=1;
            }
        }
    }
    
    minDistanceFromSource=min(minDistanceFromSource,minDistance[0][0]);
    minDistanceFromSource=min(minDistanceFromSource,minDistance[0][col-1]);
    minDistanceFromSource=min(minDistanceFromSource,minDistance[row-1][0]);
    minDistanceFromSource=min(minDistanceFromSource,minDistance[row-1][col-1]);
    
    return minDistanceFromSource==row*col?-1:minDistanceFromSource;
}

int main()
{
    int sourceRow = 3, sourceCol = 3;
    int grid[row][col] = { 1, 1, 1, 0, 0,
                           0, 0, 1, 0, 1,
                           0, 0, 1, 0, 1,
                           1, 0, 0, 0, 1,
                           1, 1, 0, 1, 0 };
 
    cout << minDistanceUtil(grid, sourceRow, sourceCol);
 
    return 0;
}