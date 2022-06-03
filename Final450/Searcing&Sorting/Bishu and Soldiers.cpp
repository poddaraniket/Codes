#include<bits/stdc++.h>
using namespace std;

int binarySearch(int sold[],int val,int s,int e)
{
    int temp=-1;
    while(s<=e)
     {
        int m=(s+e)/2;
        if(sold[m]<val)
          s=m+1;
        else if(sold[m]>val)
          e=m-1; 
        else
         {
          temp=m+1;
          s=m+1;
         }  
     }
    return temp; 
}

int main(){
    int n,q;
    cin>>n;
    int sold[n],totalPower[n+1];
    for(int i=0;i<n;i++)
     {
         cin>>sold[i];
     }
    sort(sold,sold+n);
    //cout<<"*"<<endl;
    totalPower[0]=0;
     for(int i=0;i<n;i++)
      {
        totalPower[i+1]=totalPower[i]+sold[i];
      }
    cin>>q;
    while(q--){
       // cout<<"*"<<endl;
        int power,index;
        cin>>power;
        if(sold[0]>power)
         index=0;
        else if(sold[n-1]<power)
         index=n;
        else  
         index=binarySearch(sold,power,0,n-1);
        cout<<index<<" "<<totalPower[index]<<endl;
    } 
}