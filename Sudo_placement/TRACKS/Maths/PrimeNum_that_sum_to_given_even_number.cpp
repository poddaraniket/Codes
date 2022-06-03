#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	bool a[10001];
	memset(a,true,10001);
	for(int p=2;p<=10000;p++)
	 {
	     if(a[p]==true)
	      {
	          for(int i=p*p;i<=10000;i+=p)
	           a[i]=false;
	      }
	 }
	int t;
	cin>>t;
	while(t--)
	{
	  int n,i,j;
	  cin>>n;
	  for(j=3;j<=10000;j+=2)
	   {
	     if(a[j]==true)
	       {
	         if(a[abs(n-j)]==true)
	           {
	             cout<<j<<" "<<abs(n-j)<<endl;
	             break;
	           }
	       }
	   }
	}
	return 0;
}