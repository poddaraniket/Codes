#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	    long long int n;
	    int i;
	    cin>>n;
	    for(i=2;i<=100000;i++)
	     {
	         long long int t=pow(2,i)-1;
	         if(n%t==0)
	          {
	              cout<<n/t<<endl;
	              break;
	          }
	     }
	 }
}