#include<bits/stdc++.h>
using namespace std;

int main() {
  long long int n,i,num,sum=0,m,p=0;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
   {
     cin>>num;
     sum+=num;
     a[i]=sum;
   }
  int b[sum+1];
  int c[sum+1];
  int d=1;
  for(i=0;i<=sum;i++)
   {
    // cout<<"*"<<endl;
     b[i]=i;
     if(b[i]==a[p])
      {
        p++;
        c[i]=d;
        d++;
      }
     else
       c[i]=d; 
   }
  cin>>m;
  int f[m]; 
  for(i=0;i<m;i++)
   {
     cin>>f[i];
     cout<<c[f[i]]<<endl;
   }  
}