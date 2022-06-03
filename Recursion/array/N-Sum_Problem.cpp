#include <bits/stdc++.h>
using namespace std;

bool constant(int a[],int s,int i,int n,int k)
{
    if(s==0 && k==0)
     return true;
    if(k==0 || i==n)
     return false;
    return (constant(a,s-a[i],i+1,n,k-1) || constant(a,s,i+1,n,k));
      
}

int main() {
	// your code goes here
	int n,sum,k;
	cin>>n>>sum>>k;
	int a[n];
	for(int i=0;i<n;i++)
	 cin>>a[i];
	cout<<constant(a,sum,0,n,k)<<endl;
	return 0;
}
