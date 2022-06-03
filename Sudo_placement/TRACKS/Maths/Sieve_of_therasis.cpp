#include <bits/stdc++.h>
using namespace std;

void prime(int n)
{
    //cout<<"*"<<endl;
    long long int s=0;
    bool pri[n+1];
    memset(pri, true, sizeof(pri));
    for(int p=2;p*p<=n;p++)
    {
        //cout<<"-"<<endl;
        if(pri[p]==true)
         {
             for(int i=p*p;i<=n;i+=p)
              pri[i]=false;
         }
    }
   for(int i=2;i<=n;i++) 
    {
        if(pri[i]==true)
         cout<<i<<" ";
    }
   cout<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    prime(n);
	}
	return 0;
}