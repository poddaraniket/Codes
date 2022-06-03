#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int i,n,j;
	     cin>>n;
	     int a[n],steps[n]={0},points[n];
	     for(i=0;i<n;i++)
	      cin>>a[i];
	     points[0]=-1; 
	     for(i=1;i<n;i++)
	      {
	          for(j=0;j<i;j++)
	           {
	               if(a[j]+j>=i)
	                {
	                    if(steps[i]!=0)
	                     {
	                      if(steps[i]>=steps[j]+1)
	                       {
	                         steps[i]=steps[j]+1;
	                         points[i]=j;
	                       }
	                     }
	                    else if(steps[i]==0)
	                     {
	                     steps[i]=steps[j]+1;
	                     points[i]=j;
	                     }
	                }
	           }
	      }
	     if(steps[n-1]==0 || a[0]==0)
	      cout<<"-1"<<endl;
	     else 
	      cout<<steps[n-1]<<endl; 
	 }
	return 0;
}
