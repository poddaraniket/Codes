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
	    for(int i=0;i<n;i++)
	     cin>>a[i];

        /*
        here we try to find the majorly occuring element by keeping the element that is there in ith index and  
		reducing every time we find a diff element if it occurenece is 1 then we replace the element else we reduce the count
		the last element pressent can be the majority occuring element 
		*/	
	    pair<int,int> p; 
	    p.first=a[0];
	    p.second=1;
	    for(int i=1;i<n;i++)
	     {
	        if(p.first!=a[i])
	        {
	          if(p.second==1)
	           p.first=a[i];
	          else
	           p.second--;
	        }
	        else
	         p.second++;
	     }
	    //cout<<p.first<<"*"<<endl; 

	    // the possibility is that either that element is the max occuring or it is the last element in the array that can be distinct eg-{1,2,3}

	    int count=0; 
	    for(int i=0;i<n;i++) 
	     {
	       if(p.first==a[i])
	        count++;
	     }
	    int size; 
	    if(floor(log2(n))==ceil(log2(n)))
	     size=(n/2)+1;
	    else
	     size=ceil(n/2.0);
	    //cout<<count<<"*"<<endl; 
	    if(count>=size)
	     cout<<p.first<<endl;
	    else
	     cout<<"-1"<<endl;
	}
	return 0;
}
