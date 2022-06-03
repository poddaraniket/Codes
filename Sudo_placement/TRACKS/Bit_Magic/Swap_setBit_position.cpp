#include <bits/stdc++.h>
using namespace std;

int countsetBits(int num)
{
    int i,mask=1,c=0;
    for(i=0;i<=31;i++)
     {
         if(mask&num)
          c++;
         mask<<=1; 
     }
    return c; 
}

int main() {
	// your code goes here
int t;
	cin>>t;
	while(t--)
	{
	    int n,mask=1,s=0,i=0;
	    cin>>n;
	    while(n)
	    {
	     int x=n%2;
	     n/=2;
	     int y=n%2;
	     n/=2;
	     s+=(pow(2,i)*y);
	     i++;
	     s+=(pow(2,i)*x);
	     i++;
	    }
	   cout<<s<<endl; 
	}
	return 0;
}
