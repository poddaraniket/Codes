#include <bits/stdc++.h>
using namespace std;

long long int len;
long long int p[40050];

void build(long long int a,long long int b)
{
    len=a*b;
    p[0]=0;
    for(int i=1;i<=len;i++)
    {
        p[i]=p[i-1];
        if( (i%a)%b != (i%b)%a )
          p[i]++;
    }
}

long long int query(long long int x)
{
    long long cnt=x/len;
    long long rem=x%len;
    return p[len]*cnt+p[rem];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   long long int a,b,q;
	   cin>>a>>b>>q;
	   build(a,b);
	   while(q--)
	   {
	       long long int l,r;
	       cin>>l>>r;
	       cout<<query(r)-query(l-1)<<" ";
	   }
	  cout<<endl; 
	}
	return 0;
}