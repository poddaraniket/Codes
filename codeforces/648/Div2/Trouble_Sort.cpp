#include <bits/stdc++.h>
using namespace std;
 
bool comp(pair<int,int>&a, pair<int,int>&b)
{
    if(a.second!=b.second)
     return (a.first<b.first);
    return false; 
}
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,flag=0;
	    cin>>n;
	    int a[n],b[n],one=0,zero=0,c[n];
	    for(i=0;i<n;i++)
	     {
	      cin>>a[i];
	      c[i]=a[i];
	     }
	    for(i=0;i<n;i++)
	     {
	       cin>>b[i];
	       if(b[i]==1)
	         one++;
	       else
	         zero++;
	     }
	   if(one<n && zero<n)
	    cout<<"Yes"<<endl;
	   // sort(v.begin(),v.end(),comp);
	   else
	   {
	    sort(c,c+n);    
	    for(i=0;i<n;i++)
	     {
	        if(a[i]!=c[i])
	         {
	             flag=1;
	             break;
	         }
	     }
	    if(flag  ==0)
	     cout<<"Yes"<<endl;
	    else
	     cout<<"No"<<endl;
	   }
	}
	return 0;
}