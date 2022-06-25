/*
Normal recursion but to avoid infinite loop made maze -1 when visited to notify that its visted
once its work is done in the path make it unvisited so that it can be used in some other path.

In 0,0 when we go down to 0,1 exploring 'd' and then when we go up from 0,1 to 0,0 
exlporing 't' it will go infinite there for marking it vistited

when we go 0,0->1,0->2,0->2,1->2,2->2,3->2,4->(2,5)->2,6->1,6->0,6->(0,5)->0,4->0,3->0,2->1,2 
marked all visited now after we come back to 5,4 and exlore 5,5->5,6 path and get one path 
There is one more path at min that goes from 2,1->2,2->2,3->2,4->3,4->4,4->5,4->5,5->5,6
but we cannot exlore that as its made visited so we need to mark the grid not visited on our way back from that grid(back track)
                                                                                   

                    0 1 0 0 0 0 0
                    0 1 0 1 1 1 0
                    0 0 0 0 0 0 0
                    1 0 1 1 0 1 1
                    1 0 1 1 0 1 1
                    1 0 0 0 0 0 0
*/



#include<iostream>

#include<vector>

using namespace std;
// asf -> answer so far
void floodfill(vector<vector<int>> maze, int sr, int sc, string asf) {
  //write your code here
  if(sr<0 || sc<0 || sr>=maze.size() || sc>=maze[0].size() || maze[sr][sc]!=0){
      return;
  }
  if(sr==maze.size()-1 && sc==maze[0].size()-1){
      cout<<asf<<endl;
      return;
  }
  maze[sr][sc]=-1;
  floodfill(maze, sr-1, sc, asf+'t');
  floodfill(maze, sr, sc-1, asf+'l');
  floodfill(maze, sr+1, sc, asf+'d');
  floodfill(maze, sr, sc+1, asf+'r');
  if(maze[sr][sc]==-1)
    maze[sr][sc]=0;
   
}

int main() {
  int n, m;
  cin >> n >> m;
  vector < vector < int >> arr(n, vector < int > (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  floodfill(arr, 0, 0, "");
}