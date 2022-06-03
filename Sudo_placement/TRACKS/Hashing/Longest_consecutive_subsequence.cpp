#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
   {
     int n,i,maxi=0,c=1;
     cin>>n;
     int a[n];
     for(i=0;i<n;i++)
      cin>>a[i];
     sort(a,a+n);
     for(i=1;i<n;i++)
     {
         if(a[i]-a[i-1]==1)
          {
            c++;  
          }
         else if(a[i]-a[i-1]>1)
         {
          maxi=max(maxi,c);
          c=1;
         }
     }
    cout<<max(maxi,c)<<endl; 
   }
	return 0;
}