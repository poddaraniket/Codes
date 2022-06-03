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
	    int i=speed.size()-1;
	    int swaps=0;
	    while(i>=0)
	     {
	         //cout<<i<<endl;
	         if(k==0)
	          break;
	         int dis=speed[i]*t;
	         if(dis+pos[i]>=b)
	          {
    	          k--;
    	          swap(pos[i],pos[pos.size()-1]);
    	          swap(speed[i],speed[speed.size()-1]);
    	          swaps+=(speed.size()-1)-i;
    	          pos.pop_back();
    	          speed.pop_back();
	          }
	         i--;
	     }
	    cout<<"Case #"<<c<<": "; 
	    if(k>0)
	        cout<<"Impossible"<<endl;
	    else
    	    cout<<swaps<<endl;
    	c++;    
	}
	return 0;
}
