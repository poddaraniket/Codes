#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // } Driver Code Ends


// Function to print all binary numbers upto n
void generate(ll n)
{
	// Your code here
	int i=2;
	queue<string> q;
	q.push("1");
	cout<<q.front()<<" ";
	while(i<=n)
	{
	    string t=q.front();
	    q.pop();
	    cout<<t+'0'<<" ";
	    q.push(t+'0');
	    ++i;
	    if(i<=n)
	     {
	       cout<<t+'1'<<" ";
	       q.push(t+'1');
	       ++i;  
	     }
	}
	//cout<<endl; 
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		generate(n);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends