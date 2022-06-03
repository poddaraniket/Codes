#include <bits/stdc++.h>
using namespace std;

int search(int a[],int n,int l,int r)
{
    int mid=l+(r-l)/2;
    //cout<<mid<<endl;
    if((mid==0 && a[mid]>a[mid+1]) || (mid==n-1 && a[mid]>a[mid-1]))
     return mid;
    if(mid>0 && a[mid]>a[mid-1] && a[mid]>a[mid+1])
     return mid;
    else if(mid>0 && a[mid]<a[mid-1])
     return search(a,n,l,mid-1);
    else
     return search(a,n,mid+1,r);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	     {
	         cin>>a[i];
	     }
	    //int mid=n/2; 
	    cout<<a[search(a,n,0,n-1)]<<endl;
	}
	return 0;
}
