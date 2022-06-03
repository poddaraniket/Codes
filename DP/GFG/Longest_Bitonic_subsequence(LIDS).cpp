#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
       int n,i,j;
       cin>>n;
       int a[n];
       int inc[n],dec[n];
       for(i=0;i<n;i++)
        {
            cin>>a[i];
            inc[i]=1;
            dec[i]=1;
        }
       for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
             {
                 if(a[i]>a[j] && inc[j]+1>inc[i])
                  inc[i]=inc[j]+1;
             }
        }
       for(i=n-2;i>=0;i--)
        {
            for(j=i+1;j<n;j++)
             {
                 if(a[i]>a[j] && dec[j]+1>dec[i])
                  dec[i]=dec[j]+1;
             }
        }
      int maxi=0;    
      for(i=0;i<n;i++)
       {
          maxi=max(inc[i]+dec[i]-1,maxi);
       }
       cout<<maxi<<endl;
     }
}