#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,i,j,maxi=0;
  cin>>n;
  int a[n],inc[n],dec[n];
  for(i=0;i<n;i++)
   cin>>a[i];
  inc[0]=1; 
  for(i=1;i<n;i++)
   {
     inc[i]=1;
     for(j=0;j<i;j++)
      {
        if(a[i]>a[j] && inc[i]<inc[j]+1)
         inc[i]=inc[i]+1;
      }
   }
  dec[n-1]=1; 
  for(i=n-2;i>=0;i--)
   {
     dec[i]=1;
     for(j=i+1;j<n;j++)
      {
        if(a[i]>a[j] && dec[i]<dec[j]+1)
         dec[i]=dec[j]+1;
      }
   }
  for(i=0;i<n;i++)
   {
     maxi=max(inc[i]+dec[i]-1,maxi);
   }
  cout<<maxi<<endl;   
}