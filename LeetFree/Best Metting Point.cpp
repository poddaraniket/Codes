#include <bits/stdc++.h>
using namespace std;

#define ROW 3 
#define COL 5

int minTotalDistance(int grid[ROW][COL])
{
    vector<int> hor,vert;
    queue<pair<int,int>> q;
    for(int i=0;i<ROW;i++)
     {
        for(int j=0;j<COL;j++)
         {
            if(grid[i][j]==1) 
            {
             hor.push_back(i);
             vert.push_back(j);
             q.push({i,j});
            }
         }
     }
    sort(hor.begin(),hor.end());
    sort(vert.begin(),vert.end());
    int mid=hor.size()/2;
    int x,y;
    if(hor.size()%2==0)
     {
        x=(hor[mid-1]+hor[mid])/2;
        y=(vert[mid-1]+vert[mid])/2;
     }
    else
     {
        x=hor[mid];
        y=vert[mid];
     }
    int cnt=0; 
    while(!q.empty())
     {
        cnt+=abs(q.front().first-x)+abs(q.front().second-y);
        q.pop();
     }
    return cnt; 
}

int main() { 
    int grid[ROW][COL] = {{1, 0, 1, 0, 1}, {0, 1, 0, 0, 0},{0, 1, 1, 0, 0}}; 
    cout << minTotalDistance(grid); 
    return 0; 
} 
