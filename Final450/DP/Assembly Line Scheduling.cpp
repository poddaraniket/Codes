#include <bits/stdc++.h>
using namespace std;

void carAssembly(int a[][4],int t[][4],int e[],int x[]){
    int S[2][4];
    int D[2][4];
    S[0][0]=e[0]+a[0][0];
    S[1][0]=e[1]+a[1][0];
    for(int i=1;i<4;i++)
     {
        S[0][i]=min(S[0][i-1]+a[0][i],S[1][i-1]+a[0][i]+t[1][i]);
        D[0][i]=S[0][i-1]+a[0][i]<S[1][i-1]+a[0][i]+t[1][i]?0:1;
        S[1][i]=min(S[1][i-1]+a[1][i],S[0][i-1]+a[1][i]+t[0][i]);
        D[1][i]=S[1][i-1]+a[1][i]<S[0][i-1]+a[1][i]+t[0][i]?1:0;
     }
    int index=S[0][3]+x[0]<S[1][3]+x[1]?0:1; 
    //cout<<index<<" ";
    for(int i=3;i>=1;i--)
     {
        //cout<<"*"<<index<<endl; 
        cout<<a[index][i]<<" ";
        index=D[index][i];
     }
    cout<<a[index][0]<<" "; 
    cout<<endl; 
    // return -1; 
}

int main()
{
    int a[][4] = { { 4, 5, 3, 2 },
                   { 2, 10, 1, 4 } };
    int t[][4] = { { 0, 7, 4, 5 },
                   { 0, 9, 2, 8 } };
    int e[] = { 10, 12 }, x[] = { 18, 7 };
 
     carAssembly(a, t, e, x);
 
    return 0;
}