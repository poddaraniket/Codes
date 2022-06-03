#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int count,c=1;
	cin>>count;
	while(c<=count)
	{
	    int n,k,b,t;
	    cin>>n>>k>>b>>t;
	    vector<int> pos(n),speed(n);
	    for(int i=0;i<n;i++)
	      cin>>pos[i];
	    for(int i=0;i<n;i++)
	     cin>>speed[i];
	    int i=n-1;
	    int swaps=0,notPossible=0,count=0;
	    while(i>=0)
	     {
	         //cout<<i<<endl;
	         int dis=speed[i]*t;
	         if(dis+pos[i]>=b)
	          {
    	          count++;
    	          if(notPossible>0)
    	            swaps+=notPossible;
	          }
	         else
	          {
	              notPossible++;
	          }
	         if(count>=k)
	          break;
	         i--;
	     }
	    cout<<"Case #"<<c<<": "; 
	    if(count<k)
	        cout<<"Impossible"<<endl;
	    else
    	    cout<<swaps<<endl;
    	c++;    
	}
	return 0;
}
