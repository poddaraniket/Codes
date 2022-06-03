#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n,i,s=0,c=0;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
   {
   cin>>a[i];
   }
  sort(a,a+n);
  s=a[0];
  for(i=1;i<n;i++)
   {
     if(s<=a[i])
      s+=a[i];
     else
      c++; 
   }
  cout<<n-c<<endl; 
}