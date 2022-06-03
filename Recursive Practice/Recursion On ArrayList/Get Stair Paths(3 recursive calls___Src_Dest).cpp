TC->O(N)

// Similar Q -> Get maze paths , Get maze paths with jumps

/*

E-> (n,0) n sai 0 janey kai steps
F-> (n-1,0) , (n-2,0) , (n-3,0) sai janey kai steps

F->E : add 1 to the steps you get from (n-1,0)
       add 2 to the steps you get from (n-2,0)
       add 3 to the steps you get from (n-3,0)


*/ 



#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n) {
  //Write your code here
  if(n<=0){
      vector<string> v;
      if(n==0)
       // 0 sai 0 janey ka ek tarika kharey raho
       v.push_back("");
      // 0 sai neg ja hi nhi saktey 
      return v;
  }
  vector<string> path1=get_stair_paths(n-1);
  vector<string> path2=get_stair_paths(n-2);
  vector<string> path3=get_stair_paths(n-3);
  
  vector<string> paths;
  for(string p : path1){
      p='1'+p;
      paths.push_back(p);
  }
  for(string p : path2){
      p='2'+p;
      paths.push_back(p);
  }
  for(string p : path3){
      p='3'+p;
      paths.push_back(p);
  }
  return paths;
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = get_stair_paths(n);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}