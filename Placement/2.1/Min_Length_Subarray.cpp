#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
    {
		int mini=1000000,start=0,f=0;
		long long int n,s,sum=0;
		cin>>n>>s;
		int a[n];
		for(int i=0;i<n;i++)
		 cin>>a[i];
		for(int i=0;i<n;i++)
		 {
			 sum+=a[i];
			 while(sum>=s)
			  {
				  f=1;
				  sum-=a[start];
				  start++;
			  }
			 if(f==1)
			  {
				  mini=min(mini,i-start+2);
				  f=0;
			  } 
		 }
		if(mini>n)
		 cout<<"0"<<endl;
		else
		 cout<<mini<<endl;   
	}
}