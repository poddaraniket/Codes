#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    
   int n,a,b;
   cin>>n;
   map<int,int> parent;
   parent[1]=-1;
   for(int i=0;i<n;i++)
    {
       cin>>a>>b;
       parent[b]=a;
    }
   int dist[n+1][n+1];
   for(int i=0;i<=n;i++)
    {
        dist[0][i]=0;
        dist[i][0]=0;
        dist[i][i]=0;
    }
   for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=1;j<=n;j++)
         {
            if(i==j)
             continue;
            if(i>j)
             {
                dist[i][j]=dist[j][i];
             }
            else
             {
                dist[i][j]=1+dist[i][parent[j]]; 
             }
            count+=dist[i][j]; 
         }
        cout<<count<<" "; 
    }
   cout<<endl;    
}