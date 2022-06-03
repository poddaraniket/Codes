#include<bits/stdc++.h>
using namespace std;
 
int main() {
  long long int t,a,b,c,n;
  cin>>t;
  while(t--)
   {
     long long int sum=0;
     cin>>a>>b>>c>>n;
     long long int A,B,C;
     B=(n+a-(2*b)+c)/3;
     long long temp=(n+a-(2*b)+c)%3;
     A=B-(a-b);
     C=B-(c-b);
     if(temp==0)
     {
       if(B>=0 && A>=0&&C>=0)
      cout<<"YES"<<endl;
     else
      cout<<"NO"<<endl;
     }
     else 
      cout<<"NO"<<endl;  
   }
}