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
	    int start=0,end=0;
	    while(start<n && end<n)
	     {
	         if(a[start]<=0)
	          start++;
	         if(a[end]>=0)
	          end++;
	         if(start>=end)
	          end=start+1;
	         if(a[start]>0 && a[end]<0 && end<n)
	          {
	              int reduce=min(a[start],abs(a[end]));
	              a[start]-=reduce;
	              a[end]+=reduce;
	          }
	     }
	    start=0,end=0;
	    long long int cost=0;
	    while(start<n && end<n)
	     {
	         if(a[start]>=0)
	          start++;
	         if(a[end]<=0)
	          end++;
	         if(start>=end)
	          end=start+1;
	         if(a[start]<0 && a[end]>0 && end<n)
	          {
	             // cout<<start<<" "<<end<<endl;
	              int reduce=min(abs(a[start]),a[end]);
	              cost+=reduce;
	              a[start]+=reduce;
	              a[end]-=reduce;
	          }
	     }
	    cout<<cost<<endl; 
	}
	return 0;
}