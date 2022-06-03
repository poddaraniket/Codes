#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,num;
	    cin>>n;
	    int a[n+1]={0};
	    for(int i=0;i<(2*n);i++)
	     {
	        cin>>num;
	       // cout<<num<<" ";
	        if(a[num]==0)
	         {
	             cout<<num<<" ";
	             a[num]=1;
	         }
	     }
	    cout<<endl; 
	}
	return 0;
}