//Y=(x+k)%n -> this will tell you the left one or the one being killed after this


/*

E->  soln(n,k)   -> expect this fn will tell you who survived in n,k
F->  soln(n-1,k) -> faith this fn will tell you who survived in terms of n-1,k
F->E soln(n,k) : x jo survive kargega wo nth level mai y kai terms mai - >((x+k)%n) hai
      

                                                                          ans -> 0

      0 1 2 3                                    (n=4,k=2) cut 1(0+2-1)
          2 3 0                                  new array (y) =(2+2)%4    {return y}
             |                                         |
            \ /                                       \ /    (x)=2(y below) 
          0 1 2        (treat them as new array) (n=3,k=2) cut 1(0+2-1)    
              2 0                                 new array (y) =(0+2)%3   {return y}
               |                                      |
              \ /                                    \ /    (x) = 0(y below) 
              0 1                                 (n=2,k=2) cut 1(0+2-1)
                  0                                new array (y)=(0+2)%2   {return y}
                  |                                   |       
                 \ /                                 \ /     (x)=0
                  0                               (n=1,k=2)
*/




#include<bits/stdc++.h>

using namespace std;

int solution(int n, int k){
    //write your code here
    if(n==1)
     return 0;
    int x=solution(n-1,k);
    int y=(x+k)%n;
    return y;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<solution(n,k)<<endl;
}
  