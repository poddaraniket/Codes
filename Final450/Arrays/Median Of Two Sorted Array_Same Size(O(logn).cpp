#include <bits/stdc++.h>
using namespace std;

int median(int a[],int n)
{
    if(n%2==0)
     return (a[n/2-1]+a[n/2])/2;
    return a[n/2]; 
}

int getMedian(int a1[],int a2[],int n)
{
    // for(int i=0;i<n;i++)
    //   cout<<a1[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++)
    //   cout<<a2[i]<<" ";
    // cout<<endl;
    if(n==0)
     return 0;
    if(n==1)
     return (a1[0]+a2[2])/2;
    if(n==2){
        return (max(a1[0],a2[0])+min(a1[1],a2[1]))/2;
    }
    int m1=median(a1,n);
    int m2=median(a2,n);
    if(m1==m2)
      return m1;
    if(m1<m2)
     {
        if(n%2==0)
         {
             return getMedian(a1+n/2-1,a2,n-n/2+1);
         }
        return getMedian(a1+n/2,a2,n-n/2);
     }
    if(n%2==0)
         {
             return getMedian(a1,a2+n/2-1,n-n/2+1);
         }
    return getMedian(a1,a2+n/2,n-n/2); 
}

int main() {
	int n;
	cin>>n;
	int a1[n],a2[n];
	for(int i=0;i<n;i++)
      cin>>a1[i];
    //cout<<endl;
    for(int i=0;i<n;i++)
      cin>>a2[i];
	cout<<getMedian(a1,a2,n);
	return 0;
}
