#include<bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;;
	if(n>=m)
	 cout<<n-m<<endl;
	else
	 {
	     int temp=m;
	     int count=0,sum;
	     while(temp>n)
	      { 
	        if(temp%2==0)
	         {
	             temp/=2;
	             count++;
	         }
	        else
	         {
	             temp++;
	             temp/=2;
	             count+=2;
	         }
	      }
	     if(temp==n) 
	      cout<<count<<endl; 
	     else
	      cout<<count+(n-temp)<<endl;
	 }
	return 0;
}