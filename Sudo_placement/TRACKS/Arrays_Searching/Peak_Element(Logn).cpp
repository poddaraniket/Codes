#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	 {
	 	int n,i;
	 	cin>>n;
	 	int a[n];
	 	for(i=0;i<n;i++)
	 	 {
	 	 	cin>>a[i];
	 	 }
	 	cout<<peakElement(a,n)<<endl; 	
	 }	
}

int peakElement(int arr[],int n)
 {
 if(arr[0]>arr[1])
    return 0;
   if(arr[n-1]>arr[n-2])
    return n-1;
   int l=0,r=n-1;
   while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
         return mid;
        if(arr[mid]<arr[mid+1])
          {
              l=mid+1;
          }
        else
          {
              r=mid-1;
          }
    }
}    