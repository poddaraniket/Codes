#include <bits/stdc++.h>
using namespace std;
 
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   long long int n,s=0;
	   cin>>n;
	   int t=n/2;
	   s=pow(2,n);
	   t-=1;
	   int i=1;
	   while(t--)
	   {
	      s+=pow(2,i);
	      i++;
	   }
	   long long int sum=2*(pow(2,n)-1);
	   cout<<abs((sum-s)-s)<<endl;
	}
	return 0;
}