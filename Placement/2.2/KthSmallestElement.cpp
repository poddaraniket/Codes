#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    long long int a[n];
	    priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	    //cout<<"*"<<endl; 
	    for(int i=0;i<n;i++)
		 {
			 if(i<k-1)
			  {
				  pq.push(a[i]);
				  cout<<"-1"<<" ";
			  }
			 else if(i==k-1)
			  {
				  pq.push(a[i]);
				  cout<<pq.top()<<" ";
			  } 
			 else 
			  {
				  if(a[i]>pq.top())
				   {
					   pq.pop();
					   pq.push(a[i]);
				   }
				  cout<<pq.top()<<" "; 
			  } 
		 }
		cout<<endl; 
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    long long int a[n];
	    priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	    //cout<<"*"<<endl; 
	    for(int i=0;i<n;i++)
		 {
			 if(i<k-1)
			  {
				  pq.push(a[i]);
				  cout<<"-1"<<" ";
			  }
			 else if(i==k-1)
			  {
				  pq.push(a[i]);
				  cout<<pq.top()<<" ";
			  } 
			 else 
			  {
				  if(a[i]>pq.top())
				   {
					   pq.pop();
					   pq.push(a[i]);
				   }
				  cout<<pq.top()<<" "; 
			  } 
		 }
		cout<<endl; 
	}
	return 0;
}

