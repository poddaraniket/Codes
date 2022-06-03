#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,i,num,c=0;
	     cin>>n;
	     int a[n+1]={0};
	     for(i=1;i<=n;i++)
	      {
	          cin>>num;
	          a[i]=a[i-1]+num;
	      }
	   //  for(i=0;i<=n;i++) 
	   //   cout<<a[i]<<" ";
	   //  cout<<endl; 
	     if(n>1)
	     {
	     for(i=1;i<=n;i++)
	      {
	          if((a[n]-a[i])==a[i-1])
	           {
	               c=1;
	               cout<<i<<endl;
	               break;
	           }
	      }
	      if(c==0)
	       cout<<"-1"<<endl;
	     }
	    else
	      cout<<"1"<<endl;
	 }
	return 0;
}
