#include <bits/stdc++.h>
using namespace std;

int maxi=-1;

void maxIndex(int arr[],int n,int l,int r)
{
    if(l==r)
     {
        return; 
     }
    if(arr[l]<=arr[r])
     maxi=max(maxi,r-l);
    maxIndex(arr,n,l+1,r);
    maxIndex(arr,n,l,r-1);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	 int n;
	 cin>>n;
	 maxi=-1;
	 int arr[n]; 
     for(int i=0;i<n;i++)
      cin>>arr[i];
     maxIndex(arr,n,0,n-1);
     cout<<maxi<<endl;
	}
	return 0;
}


/*
Another Approach

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;++i)
	     cin>>a[i];
	    if(n==1)
	     cout<<"0"<<endl;
	    else
	    {
	    long long int LMIN[n],RMIN[n];
	    LMIN[0]=a[0];
	    for(int i=1;i<n;i++) 
	     LMIN[i]=min(LMIN[i-1],a[i]);
	    RMIN[n-1]=a[n-1]; 
	    for(int i=n-2;i>=0;--i) 
	     {
	        RMIN[i]=max(RMIN[i+1],a[i]);
	     }
	    int i=0,j=0,maxi=-1;
	    while(i<n && j<n)
	    {
	        if(LMIN[i]<=RMIN[j])
	         {
	             maxi=max(maxi,j-i);
	             j=j+1;
	         }
	        else
	         i=i+1;
	    }
	    cout<<maxi<<endl;
	    }
	}
	return 0;
}
*/