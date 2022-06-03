#include <bits/stdc++.h>
using namespace std;
 
int gcd(int b,int a)
{
    if(a==0)
     return b;
    return gcd(a,b%a); 
}
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    bool vis[n];
	    memset(vis,false,sizeof(vis));
	    int arr[n],b[n],maxi=0,loc;
	    for(int i=0;i<n;i++)
	     {
	         cin>>arr[i];
	         if(maxi<arr[i])
	          {
	              maxi=arr[i];
	              loc=i;
	          }
	     }
	    //cout<<arr[loc]<<endl; 
	    b[0]=arr[loc];
	    vis[loc]=true;
	    int lastnum=b[0];
	    //cout<<"*"<<endl;
	    for(int i=1;i<n;i++)
	     {
	         maxi=0;
	         for(int j=0;j<n;j++)
	          {
	              if(vis[j]==false)
	               {
	                   int num=gcd(lastnum,arr[j]);
	                   if(num>maxi)
	                    {
	                        //cout<<arr[j]<<endl;
	                        loc=j;
	                        maxi=num;
	                    }
	               }
	          }
	         lastnum=maxi; 
	         vis[loc]=true;
	         b[i]=arr[loc];
	     }
	    for(int i=0;i<n;i++)
	     cout<<b[i]<<" ";
	    cout<<endl; 
	}
	return 0;
}