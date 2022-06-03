/*
E-> (sx,sy,dx,dy)

F-> (sx+1,sy,dx,dy) && (sx,sy+1,dx,dy)

F->E : add 'v' on path from (sx+1,sy,dx,dy) && 'h' on path from (sx,sy+1,dx,dy)

*/


#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr==dr && sc==dc){
        vector<string> v;
        v.push_back("");
        return v;
    }
    
    vector<string> path1,path2;
    
    if(sc+1<=dc){
        path1=getMazePaths(sr,sc+1,dr,dc);
    } 
    
    if(sr+1<=dr){
     path2=getMazePaths(sr+1,sc,dr,dc);
    }
    
    vector<string> paths;
    
     for(string p : path1){
        p='h'+p;
        paths.push_back(p);
    }
    
    for(string p : path2){
        p='v'+p;
        paths.push_back(p);
    }
    
    
    
    return paths;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}



/*

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr==dr && sc==dc){
        vector<string> v;
        v.push_back("");
        return v;
    }
    
    vector<string> paths;
    
    vector<string> path1,path2;
    
    if(sc+1<=dc){
        path1=getMazePaths(sr,sc+1,dr,dc);
         for(string p : path1){
            p='h'+p;
            paths.push_back(p);
        }
    } 
    
    if(sr+1<=dr){
     path2=getMazePaths(sr+1,sc,dr,dc);
      for(string p : path2){
        p='v'+p;
        paths.push_back(p);
     }
    }
    return paths;
}


*/