#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	   int a,b,i,c=0,mask=1;
	   cin>>a>>b;
       for(i=0;i<=31;i++)
        {
         int x=mask&a;
         int y=mask&b;
         if(x!=y)
          c++;
         mask<<=1;
        }
	   cout<<c<<endl; 
	}
	return 0;
}
