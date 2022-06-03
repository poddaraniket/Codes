#include <bits/stdc++.h>
using namespace std;
 
char a[1000000];
 
int getCost(int l,int r,char ch)
{
    int cnt=0;
    for(int i=l;i<=r;i++)
     {
        if(a[i]!=ch)
         cnt++;
     }
    return cnt; 
}
 
int getMin(int l,int r,char ch)
{
    if(l==r)
     {
        if(a[l]==ch)
         return 0;
        else
         return 1;
     }
    int mid=(l+r)/2;
    return min((getCost(l,mid,ch)+getMin(mid+1,r,ch+1)),(getCost(mid+1,r,ch)+getMin(l,mid,ch+1)));
}
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    //char a[n];
	    for(int i=0;i<n;i++)
	     {
	         cin>>a[i];
	     }
	    cout<<getMin(0,n-1,'a')<<endl; 
	}
	return 0;
}