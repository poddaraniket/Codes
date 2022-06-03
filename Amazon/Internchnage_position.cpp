#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    //stack<int> s;
	    for(int i=0;i<n;i++)
	     cin>>a[i];

	    //store old position as remanider and new val as quotient so when u divide by the number u can get that val
	    for(int i=0;i<n;i++)
	     {
	       a[i]=a[i]+((a[a[i]]%n)*n);  
	     }
	    for(int i=0;i<n;i++)
	     cout<<a[i]/n<<" ";
	    cout<<endl; 
	}
	return 0;
}
