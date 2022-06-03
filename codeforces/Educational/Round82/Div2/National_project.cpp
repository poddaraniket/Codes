#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     long long int n,g,b,temp,good,ans,bad;
	     cin>>n>>g>>b;
	     if(n<=g)   
	      cout<<n<<endl;
	     else
	      {
	         if(n%2==0)
	          temp=n/2;
	         else
	          temp=(n/2)+1;
	         good=temp/g;                                       
	         if(temp%g==0)
	           ans=(good-1)*b+(good*g);
	         else
	            ans=good*b+good*g+(temp%g);
	         cout<<max(ans,n)<<endl;   // eg-20 10 10 ans->20 not 10
	      }
	 }
	return 0;
}
