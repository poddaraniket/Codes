#include <bits/stdc++.h>
using namespace std;
 
int ask(int x,int y)
{
    cout<<"? "<<x+1<<" "<<y+1<<endl;
    int mod;
    cin>>mod;
    return mod;
}
 
int main() {
	// your code goes here
	int n;
	cin>>n;
	int ans[n]={0};
	int mx=0;
	for(int i=1;i<n;i++)
	 {
	    int a=ask(mx,i);
	    int b=ask(i,mx);
	    if(a>b)
	     {
	         ans[mx]=a;
	         mx=i;
	     }
	    else
	     {
	         ans[i]=b;
	     }
	 }
	ans[mx]=n;
	cout<<"!";
	for(int i=0;i<n;i++)
	 cout<<" "<<ans[i];
	cout<<endl; 
	return 0;
}