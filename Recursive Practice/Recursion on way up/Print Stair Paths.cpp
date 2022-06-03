// prerequisite-> get stair case path & print subsequence


/*
    if(step<0) -> end of journey not an answer
    if(step==0)-> end of jpurney and an answer
          step-1|psf+'1'  step-2+'2'  step-3+'3'
                     \       |       /
                          step|psf


           0|111 -1|112 -2|113
                \   |   /
                   1|11   0|12 -1|13
                       \   |   /   0|21 -1|22 -2|23
                        \  |  /       \  |   /
                          2|1          1|2
                               \        |    0|3
                                \       |    /
                                 \      |   /
                                       3|.
*/
#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    // write your code here
    if(n<=0){
        if(n==0)
         cout<<psf<<endl;
        return;
    }
    printStairPaths(n-1,psf+'1');
    printStairPaths(n-2,psf+'2');
    printStairPaths(n-3,psf+'3');
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}