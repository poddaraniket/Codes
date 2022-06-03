#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0,temp,i;
	    cin>>n;
	    int a[n];
	    //vector<int> b;
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	    temp=a[0];
	    for(i=1;i<n;i++)
	     {
	         if(a[i]<a[i-1])
	          {
	             sum+=a[i-1]-temp;
	             temp=a[i];
	          }
	     }
	    sum+=a[i-1]-temp; 
	    cout<<sum<<endl; 
	}
	return 0;
}
