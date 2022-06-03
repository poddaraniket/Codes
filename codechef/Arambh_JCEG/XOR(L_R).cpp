#include<bits/stdc++.h>
using namespace std;

long long int xo(long long int n)
 {
   if(n%4==0)
    return n;
   else if(n%4==1)
    return 1;
   else if(n%4==2)
    return(n+1);
   else 
    return 0;  
 }

int main() {
     int t;
     cin>>t;
     while(t--)
      {
        long long int l,r;
        cin>>l>>r;
        long long int y=xo(l-1);
        long long int f=xo(r);
        long long int d=f^y;
        cout<<d<<endl;
      }
}