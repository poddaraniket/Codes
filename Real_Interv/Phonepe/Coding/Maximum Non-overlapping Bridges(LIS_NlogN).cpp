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

void binarySearch(int l,int h,int LIS[],int val)
{
    int best=-1;
    while(l<=h)
     {
        int m=l+(h-l)/2;
        if(LIS[m]<=val)
         {
            l=m+1;
            best=m;
         }
        else
         {
             h=m-1;
         }
     }
    LIS[best+1]=val; 
}

void nonOverlapping(Bridges points[],int n)
{
    sort(points,points+n,compare);
    int LIS[n+1];
    LIS[0]=-1;
    for(int i=1;i<=n;i++)
     LIS[i]=101;
    for(int i=0;i<n;i++)
     {
        binarySearch(0,n,LIS,points[i].south); 
     }
    for(int i=n;i>=0;i--)
     {
         if(LIS[i]<101)
          {
            cout<<i<<endl;
            break;
          }
     }
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