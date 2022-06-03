#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   int n,i,c=-1;
	   cin>>n;
	   int a[n];
	   for(i=0;i<n-1;i++)
	    {
	        cin>>a[i];
	    }
	   sort(a,a+(n-1));
	   for(i=0;i<n-1;i++)
	    {
	        if((i+1)^a[i])
	        {
	         c=i+1;
	         break;
	        }
	    }
	   if(c==-1)
	    cout<<n<<endl;
	   else
	    cout<<c<<endl;
	}
	return 0;
}