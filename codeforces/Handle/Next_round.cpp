#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k,c=0,i;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
	 {
	     cin>>a[i];
	     if(i<=(k-1))
	      {
	          if(a[i]>0)
	            c++;
	      }
	     if(i>(k-1))
	      {
	          if(a[i]==a[k-1] && a[i]>0)
	           c++;
	      }
	 }
	cout<<c<<endl; 
	return 0;
}
