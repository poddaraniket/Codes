#include <bits/stdc++.h>
using namespace std;

int search(int a[],int target,int low,int high,int n)
{
    if(low>high)
     return -1;
    int mid=(low+high)/2;
    if(a[mid]==target)
     return mid;
    else if(a[mid]>target)
     return search(a,target,low,mid-1,n);
    else
     return search(a,target,mid+1,high,n);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],maxi=-1,loc;
	    for(int i=0;i<n;i++)
	    {
	     cin>>a[i];
	     if(maxi<a[i])
	      {
	          maxi=a[i];
	          loc=i;
	      }
	    }
	    int target;
	    cin>>target;
	    if(target<a[0])
	     {
	        cout<<search(a,target,loc+1,n-1,n)<<endl; 
	     }
	    else
	     {
	        cout<<search(a,target,0,loc,n)<<endl; 
	     }
	}
	return 0;
}
