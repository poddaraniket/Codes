#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    long long int a[n],nextgreat[n];
	    for(int i=0;i<n;i++)
	     {
	         cin>>a[i];
	     }
	     
	    stack<long long int> s;
	    for(int i=n-1;i>=0;i--)
	     {
	         //cout<<"*"<<endl;
	     	// if the element in the array is greater than that in stack top than keep removing till u get the gretere element
	         while(!s.empty())
	          {
	              if(a[i]<=s.top())
	               break;
	              s.pop();
	          }
	         
 			// if no next greater element exist then that stack is empty and u print -1

	         if(s.empty())
	          { 
	           nextgreat[i]=-1;
	          }
	         else
	          {
	           nextgreat[i]=s.top();
	          }
	         s.push(a[i]);
	        //cout<<nextgreat[i]<<" "; 
	     }
	    //cout<<endl; 
	    for(int i=0;i<n;i++)
	     cout<<nextgreat[i]<<" ";
	    cout<<endl; 
	}
	return 0;
}