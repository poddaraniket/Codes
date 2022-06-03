#include<bits/stdc++.h>
using namespace std;

int n;
double a[101];

double check(double x)
{
    double ans=0.0;
    for(int i=0;i<n;i++)
     {
         ans+=(1/(x-a[i]));
     }
    return ans; 
}

double bin(double l,double r)
{
    double mid,val;
    while(l<r)
     {
        mid=r+(l-r)*0.5;
        //cout<<mid<<endl;
        val=check(mid);
        if(abs(val)< 0.0000000000001)
         return mid;
        if(val>0)
         l=mid;
        else
         r=mid;
     }
    return l; 
}

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
      int i;
      cin>>n;
      for(i=0;i<n;i++)
       {
           cin>>a[i];
       }
      for(int i=1;i<n;i++)
       {
            printf("%.2f ",bin(a[i-1],a[i]));
       }
      cout<<endl; 
    }
}