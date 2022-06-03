#include<bits/stdc++.h>
using namespace std;

int main() {
     int t,i,j;
     cin>>t;
     while(t--)
      {
        int n,i,c=0;
        cin>>n;
        int a[n][2];
        for(i=0;i<n;i++)
         {
           cin>>a[i][0]>>a[i][1];
         }
        for(i=0;i<n;i++)
         {
           for(j=i+1;j<n;j++)
            {
              if(a[i][0]!=a[j][0] && a[i][1]!=a[j][1])
               c++;
            }
         }
        cout<<c<<endl;  
      }
}