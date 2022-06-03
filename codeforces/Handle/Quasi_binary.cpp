#include <bits/stdc++.h>
using namespace std;

int a[100]={0};

void solve(int n,int m)
 {
     int power=pow(10,m);
     for(int i=0;i<n;i++)
     {
         if(power==1)
          a[i]=1;
         else
          {
            a[i]+=power;    
          }
     }
 }

int main() {
	// your code goes here
	int i,n,c=0;
	cin>>n;
	while(n)
	 {
	     int rem=n%10;
	     solve(rem,c);
	     n/=10;
	     c++;
	 }
	c=0; 
	for(i=0;i<100;i++)
	 {
	     if(a[i]!=0)
	      c++;
	     else 
	       break; 
	 }
	cout<<c<<endl; 
	for(int j=0;j<i;j++) 
	 cout<<a[j]<<" ";
	cout<<endl; 
	return 0;
}
