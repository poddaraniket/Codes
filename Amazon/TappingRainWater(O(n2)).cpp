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
	for(int i=0;i<n;i++)
	 {
	     int lmax=maxheight(a,0,i-1);
	     int rmax=maxheight(a,i+1,n-1);
	     //cout<<lmax<<" "<<rmax<<endl;
	     int minlevel=min(lmax,rmax);
	     //cout<<minlevel<<endl;
	     if(minlevel>a[i])
	      totalvol+=(minlevel-a[i]);
	 }
	cout<<totalvol<<endl;
	return 0;
}
