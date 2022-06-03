//O(n) O(1)

#include <bits/stdc++.h>
using namespace std;

int Derange(int n)
{
    if(n==1){
     return 0;
    }
    if(n==2)
     {
        return 1; 
     }
    int a=0,b=1;
    int c;
    for(int i=3;i<=n;i++)
     {
        // a->means if the alpahbet is placed at i then we have two letters swapped see for n-2 elements 
        // b->means if the alpahbet is not placed at i then we have no letters swapped see for n-1 elements 
        c=(i-1)*(a+b);
        a=b;
        b=c;
     }
    return c; 
}

int main() {
    int n;
    cin>>n;
    cout<<Derange(n)<<endl;
	return 0;
}
