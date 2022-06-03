#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
  //Write your code here
  
  if(sr==dr && sc==dc)
  {
     vector<string> v;
     v.push_back("");
     return v;
  }
  
  vector<string> paths;
  
  for(int h=1;h<=dc-sc;h++){
      vector<string> hPath=get_maze_paths(sr,sc+h,dr,dc);
      // we cannot solve this like simpe maze problem (below loop in postorder region) bcoz we do not have data for ho long the jump was
      for(string p : hPath){
         p='h'+to_string(h)+p;
         paths.push_back(p);
      }
  }
  for(int v=1;v<=dr-sr;v++){
      vector<string> vPath=get_maze_paths(sr+v,sc,dr,dc);
      for(string p : vPath){
         p='v'+to_string(v)+p;
         paths.push_back(p);
      }
  }
  for(int d=1;d<=min(dc-sc,dr-sr);d++){
      vector<string> dPath=get_maze_paths(sr+d,sc+d,dr,dc);
      for(string p : dPath){
         p='d'+to_string(d)+p;
         paths.push_back(p);
      }
  }
  
  return paths;
}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);

  return 0;
}