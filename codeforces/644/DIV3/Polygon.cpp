#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int i,n,count=0,j,c=0;
	    cin>>n;
	    char a[50][50];
	    for(i=0;i<n;i++)
	     {
	         for(j=0;j<n;j++)
	          {
	            cin>>a[i][j];
	            if(a[i][j]=='0')
	             count++;
	          }
	     }
	   // for(i=1;i<=n;i++)
	   //  {
	   //      for(j=1;j<=n;j++)
	   //       {
	   //         cout<<a[i][j]<<" ";
	   //       }
	   //      cout<<endl; 
	   //  } 
	   // cout<<"*"<<count<<endl; 
	    if(count==(n*n))
	     cout<<"YES"<<endl;
	    else
	    {
	     //cout<<"**"<<endl;     
	     for(i=0;i<n-1;i++)
	      {
	         for(j=0;j<n-1;j++)
	          {
	              if(a[i][j]=='1')
	               {
	                   if(a[i][j+1]=='0' && a[i+1][j]=='0')
	                    {
	                        c=1;
	                        break;
	                    }
	               }
	          }
	         if(c==1)
	          break;
	      }
	     if(c==1)
	      cout<<"NO"<<endl;
	     else
	      cout<<"YES"<<endl;
	    }
	}
	return 0;
}