#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,k,i;
	     cin>>n>>k;
	     int a[n];
	     for(i=0;i<n;i++)
	      cin>>a[i];
	     deque<int> dq(k);   // double ended queue
	     for(i=0;i<k;i++)
	      {
	          while((!dq.empty()) && a[i]>=a[dq.back()])
	           dq.pop_back();
	          dq.push_back(i);    
	      }
	     for(;i<n;i++)
	      {
	          cout<<a[dq.front()]<<" ";
	          while((!dq.empty()) && dq.front()<=i-k)
	           dq.pop_front();
	          while((!dq.empty()) && a[i]>=a[dq.back()])
	           dq.pop_back();
	          dq.push_back(i);    
	      }
	     cout<<a[dq.front()]<<endl; 
	 }
	return 0;
}
