#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],mini[n],maxi[n];
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	    mini[0]=a[0];
	    for(int i=1;i<n;i++)
	     {
	         mini[i]=min(mini[i-1],a[i]);
	     }
	    maxi[n-1]=a[n-1];
	    for(int i=n-2;i>=0;i--)
	     maxi[i]=max(maxi[i+1],a[i]);
	    int ans=0; 
	    for(int i=0;i<n;i++)
	     {
	         ans=max(ans,maxi[i]-mini[i]);
	     }
	    if(ans==0)
	     cout<<"-1"<<endl;
	    else
	     cout<<ans<<endl;
	}
	return 0;
}