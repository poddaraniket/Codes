#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
	   int n,m,i,j;
	   cin>>n;
	   int a[n],curr;
	   for(i=0;i<n;i++)
	   {
	    cin>>a[i];
	    //lis[i]=1;
	    //d[n]=
	   }
	   cin>>m;
	   int b[m],table[m]={0};
	   for(i=0;i<m;i++)
	   {
	       cin>>b[i];
	   }
	   for(i=0;i<n;i++)
	    {
	       curr=0;
	       {
	           for(j=0;j<m;j++)
	            {
	                if(a[i]==b[j])
	                 {
	                    if(curr+1>table[j])
	                     table[j]=curr+1;
	                 }
	                if(a[i]>b[j])
	                 {
	                     if(table[j]>curr)
	                      curr=table[j];
	                 }
	            }
	       }
	    }
	    int maxi=0;
	   for(i=0;i<m;i++)
	    {
	        maxi=max(table[i],maxi);
	    }
	   cout<<maxi<<endl; 
    }
}