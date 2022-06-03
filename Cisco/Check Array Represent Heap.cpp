#include <iostream>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,f=1;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) 
	     cin>>a[i];
	    for(int i=0;i<n;i++)
	     {
	         if((2*i)+1<n && a[i]<a[(2*i)+1])
	          {
	              f=0;
	              break;
	          }
	         if((2*i)+2<n && a[i]<a[(2*i)+2])
	          {
	              f=0;
	              break;
	          } 
	     }
	    cout<<f<<endl;
	}
	return 0;
}