#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long int m,n,row,col,s=0;
	    cin>>m>>n;
	    row=m;
	    col=n;
	    for(int i=1;i<=min(m,n);i++)
	     {
	         s+=row*col;
	         row--;
	         col--;
	     }
	    cout<<s<<endl; 
	}
	return 0;
}