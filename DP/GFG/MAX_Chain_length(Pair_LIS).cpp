#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	    int n,i,j;
	    cin>>n;
	    int a[2*n];
	    vector<pair<int,int>> v;
	    for(i=0;i<2*n;i++)
	     cin>>a[i];
	    for(i=0;i<2*n;i+=2)
	     {
	         v.push_back(make_pair(a[i],a[i+1]));
	     }
	    sort(v.begin(),v.end());
	    
	    int lis[n];
	    for(i=0;i<n;i++)
	     {
	      lis[i]=1;
	     }
	      
	    for(i=1;i<n;i++)
	     {
	        for(j=0;j<i;j++)
	         {
	             if(v[j].second<v[i].first && lis[j]+1>lis[i])
	              lis[i]=lis[j]+1;
	         }
	     }
	    cout<<lis[n-1]<<endl; 
	 }
	return 0;
}
