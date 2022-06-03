#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,i,ce=0,co=0,le,lo;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
   {
     cin>>a[i];
     if(a[i]%2==0)
      {
        ce++;
        le=i;
      }
     else
     {
       co++;
       lo=i; 
     }
   }
  if(ce==1)
   cout<<le+1<<endl;
  else if(co==1)
   cout<<lo+1<<endl; 
}