#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,plt=1,maxi=1;
	    cin>>n;
	    int arr[n],dep[n];
	    for(int i=0;i<n;i++)
	     {
	      cin>>arr[i];
	     }
	    for(int i=0;i<n;i++)
	     {
	      cin>>dep[i];
	     } 
	    sort(arr,arr+n);
	    sort(dep,dep+n);
	    int i=1,j=0; 
	    while(i<n && j<n)
	     {
	         if(arr[i]<=dep[j])
	          {
	           plt++;
	           i++;
	          }
	         else if(arr[i]>dep[j]) 
	          {
	              plt--;
	              j++;
	          }
	         maxi=max(plt,maxi);
	     }
	    cout<<maxi<<endl; 
	}
	return 0;
}
