#include <bits/stdc++.h>
using namespace std;

int search(int num,int b[],int n)
{
    int l=0,r=n-1;
    if(num<b[0])
     return 0;
    if(num>=b[n-1])
     return n;
    while(l<=r)
     {
        int mid=(l+r)/2;
        if(b[mid+1]>num)
         {
            if(b[mid]<=num)
             return mid+1;
            else
             r=mid-1;
         }
        else
         {
            l=mid+1; 
         }
     }
     
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int a[m],b[n];
	    for(int i=0;i<m;i++)
	     cin>>a[i];
	    for(int i=0;i<n;i++)
	     cin>>b[i];
	    sort(b,b+n);
	    int i=0;
	    int count[m]={0};
	    while(i<m)
	     {
	        count[i]=search(a[i],b,n);
	        //cout<<"*"<<endl;
	        i++;
	     }
	    for(int i=0;i<m;i++)
	     cout<<count[i]<<" ";
	    cout<<endl; 
	}
	return 0;
}
