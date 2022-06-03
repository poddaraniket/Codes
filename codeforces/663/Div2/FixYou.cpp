#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,c=0;
        cin>>n>>m;
        char dir;
        for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
              {
                cin>>dir; 
                if(i==n-1 && dir=='D')
                 {
                    c++;
                 }
                else if(j==m-1 && dir=='R')
                 {
                    c++; 
                 }
              }   
         }
        cout<<c<<endl; 
    }
}