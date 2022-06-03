#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	   int n,k,i,j,count;
	   cin>>n>>k;
	   //count=k;
	   int a[n];
	   int b[100001]={0};
	   for(i=0;i<n;i++)
	    cin>>a[i];
	   for(i=0;i<k;i++)
	    {
	        if(b[a[i]]==0)
	         count++;
	        b[a[i]]++;
	    }
	   cout<<count<<" ";
	   for(i=k;i<n;i++)
	    {
	        if(b[a[i-k]]==1)
	         count--;
	        b[a[i-k]]--;
	        if(b[a[i]]==0)
	         count++;
	        b[a[i]]++;
	        cout<<count<<" ";
	    }
	   cout<<endl; 
	 }
	return 0;
}
