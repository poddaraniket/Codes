// prerequisite-> get maze path & print subsequence



/* 
                    (sr,sc+1)+psf+'h'   (sr+1,sc)+psf+'v'
                            \                / 
                                (sr,sc)|psf


                              (1,1)|hv  (1,1)|vh
                               /            \
                        (0,1)|h             (1,0)|v
                              \            /
                               \          /
                                  (0,0)|.  

*/

#include <iostream>
using namespace std;


// Call smart , Base Case Normal
void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    // write your code here
    if(sr==dr && sc==dc){
        cout<<psf<<endl;
        return;
    }
    if(sc<dc){
        printMazePaths(sr,sc+1,dr,dc,psf+'h');
    }
    if(sr<dr){
        printMazePaths(sr+1,sc,dr,dc,psf+'v');
    }
}


/*
// Call Normal, Base Case Smart
                    x                               x    
                 (0,2)|hh    (1,1)|hv  (1,1)|vh  (2,1)|vv 
                        \       /            \    /
                        (0,1)|h             (1,0)|v
                              \            /
                               \          /
                                  (0,0)|.  



void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    // write your code here
    if(sr>dr || sc>dc)
      return;
    if(sr==dr && sc==dc){
        cout<<psf<<endl;
        return;
    }
    printMazePaths(sr,sc+1,dr,dc,psf+'h');
    printMazePaths(sr+1,sc,dr,dc,psf+'v');
}

*/

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}