#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,zero=0,one=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	     {
	         cin>>a[i];
	         if(i%2==0 && a[i]%2!=0)
	          zero++;
	         if(i%2!=0 && a[i]%2==0)
	          one++;
	     }
	    if(one==zero)
	     cout<<one<<endl;
	    else
	     cout<<"-1"<<endl;
	}
	return 0;
}