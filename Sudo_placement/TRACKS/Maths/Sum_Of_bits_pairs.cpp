#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	  long long int n,i,s=0,j;
	  cin>>n;
	  int a[n],one[31]={0},zero[31]={0};
	  for(i=0;i<n;i++)
	   {
	      cin>>a[i];
	   }
	  for(i=0;i<=31;i++)
	   {
	       for(j=0;j<n;j++)
	        {
	           //cout<<"*"<<a[j]<<" "; 
	           if((a[j]&1)==1)
	            one[i]++;
	           else
	            zero[i]++;
	           a[j]>>=1; 
	           //cout<<a[j]<<endl;
	        }
	   }
	  for(i=0;i<31;i++)
	   s=(s+(zero[i]*one[i])%1000000007)%1000000007;
	  cout<<(2*s)%1000000007<<endl; 
	}
	return 0;
}