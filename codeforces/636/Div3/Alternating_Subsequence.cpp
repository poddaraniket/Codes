#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	   long long int n,i,neg=0,pos=0,maxi=0,mini=-2000000000,s=0,t;
	   cin>>n;
	   long long int a[n];
	   for(i=0;i<n;i++)
	    cin>>a[i];
	//   cout<<"*]"<<a[0]<<endl; 
	   if(a[0]<0)
	   {
	    neg=1;
	    mini=max(mini,a[0]);
	   }
	   else
	    {
	    pos=1;
	    maxi=max(maxi,a[0]);
	    }
	  // cout<<"*/"<<maxi<<endl; 
	   for(i=1;i<n;i++)
	    {
	        if(pos==1)
	         {
	             if(a[i]<0)
	              {
	                  //+++
	                  //cout<<"*"<<maxi<<endl;
	                  s+=maxi;
	                  maxi=0;
	                  neg=1;
	                  mini=max(mini,a[i]);
	                  pos=0;
	              }
	             else
	              maxi=max(maxi,a[i]);
	         }
	        else if(neg==1)
	         {
	             if(a[i]>0)
	              {
	                 // cout<<"*"<<mini<<endl;
	                  s+=mini;
	                  mini=-2000000000;
	                  pos=1;
	                  maxi=max(a[i],maxi);
	                  neg=0;
	              }
	             else
	              mini=max(mini,a[i]);
	         }
	    }
	   if(pos==1)
	    s+=maxi;
	   else
	    s+=mini;
	   cout<<s<<endl; 
	 }
}