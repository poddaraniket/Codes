#include <iostream>
using namespace std;

int MaxXorArray(int a[],int n,int i,int f)
{
    if(i==n)
     {
         return f;
     }
    return max(MaxXorArray(a,n,i+1,f^a[i]),MaxXorArray(a,n,i+1,f)); 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	     cin>>a[i];
	    cout<<MaxXorArray(a,n,0,0)<<endl;; 
	}
	return 0;
}
