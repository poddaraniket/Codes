#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,maxi=0,mini=100000,cntmax=0,cntmin=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	     {
	        cin>>a[i];
	        if(a[i]>maxi)
	        {
	         cntmax=1;
	         maxi=a[i];
	        }
	        else if(a[i]==maxi)
	         cntmax++;
	        if(a[i]<mini)
	         {
	             cntmin=1;
	             mini=a[i];
	         }
	        else if(a[i]==mini)
	         cntmin++;
	     }
	    int maxcom=1,mincom=1; 
	    while(cntmin--)
	     {
	        mincom=(mincom*2)%1000000007; 
	     }
	    while(cntmax--)
	     {
	        maxcom=(maxcom*2)%1000000007; 
	     } 
	    cout<<maxcom-1<<" "<<mincom-1<<endl; 
	}
	return 0;
}