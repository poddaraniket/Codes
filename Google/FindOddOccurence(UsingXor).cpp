#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    n=(n*2)+2;
	    long long int a[n];
	    long long int xored_sum=0;
	    for(int i=0;i<n;i++)
	     {
	      cin>>a[i];
	      xored_sum^=a[i];
	     } 
	    int set_bit=(xored_sum)&~(xored_sum-1);
	    int x=0,y=0;
	    for(int i=0;i<n;i++)
	     {
	         if(set_bit&a[i])
	          x^=a[i];
	         else
	          y^=a[i];
	     }
	    cout<<min(x,y)<<" "<<max(x,y)<<endl; 
	}
	return 0;
}