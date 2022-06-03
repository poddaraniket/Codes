//O(N^2)

#include<bits/stdc++.h>
using namespace std;

struct Bridges{
    int north,south;
   
};

bool compare(struct Bridges a,struct Bridges b){
    if(a.north==b.north)
     return a.south<b.south;
    return a.north<b.north;
}

void nonOverlapping(Bridges points[],int n)
{
    sort(points,points+n,compare);
    int LIS[n];
    for(int i=0;i<n;i++)
     LIS[i]=1;
    int ans=1;
    for(int i=1;i<n;i++)
     {
         for(int j=0;j<i;j++)
          {
            if(points[i].south>=points[j].south && LIS[i]<LIS[j]+1)
             {
                 LIS[i]=LIS[j]+1;
                 ans=max(ans,LIS[i]);
             }
          }
     }
    cout<<ans<<endl; 
}

int main(){
    int n;
    cin>>n;
    int a,b;
    Bridges points[n];
    for(int i=0;i<n;i++)
     {
        cin>>a>>b;
        points[i].north=a;
        points[i].south=b;
     }
    nonOverlapping(points,n);
    return 0;
}