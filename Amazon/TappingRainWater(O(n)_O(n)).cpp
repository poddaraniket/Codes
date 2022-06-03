#include <bits/stdc++.h>
using namespace std;

int maxheight(int a[],int l,int r)
{
    int maxi=0;
    if(l>r)
     return 0;
    for(int i=l;i<=r;i++)
     maxi=max(maxi,a[i]);
    return maxi; 
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	//stack<int> s;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	int totalvol=0; 
	int lmax[n],rmax[n];
	lmax[0]=a[0];
	for(int i=1;i<n;i++)
	  lmax[i]=max(lmax[i-1],a[i]);
	rmax[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	 rmax[i]=max(rmax[i+1],a[i]);
	for(int i=0;i<n;i++)
	 {
	     //cout<<lmax<<" "<<rmax<<endl;
	     int minlevel=min(lmax[i],rmax[i]);
	     //cout<<minlevel<<endl;
	     if(minlevel>a[i])
	      totalvol+=(minlevel-a[i]);
	 }
	cout<<totalvol<<endl;
	return 0;
}
