
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	     //int dp[1001]={0};
	     long long int n,s=0,i=1,l,r,mask=1;
	     cin>>n>>l>>r;
	     while(i<l)
	      {
	        if(n&mask)
	         s+=pow(2,i-1);
	        mask<<=1;
	        i++;
	      }
	     while(i<=r)
	      {
	         if(!(n&mask))
	          s+=pow(2,i-1);
	         mask<<=1;
	         i++; 
	      }
	    while(i<=10)
	     {
	        if(n&mask)
	         s+=pow(2,i-1);
	        mask<<=1;
	        i++; 
	     }
	    cout<<s<<endl; 
	 }
}