#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
	int n,inc=0,dec=0,maxi=0,i;
	cin>>n;
	long long int a[n];
	for(i=0;i<n;i++)
	 cin>>a[i];
	for(i=0;i<n-1;i++)
	 {
	     if(maxi<a[i])
	      maxi=a[i];
	     if(a[i]>a[i+1])
	      {
	          dec++;
	      }
	     else
	       inc++;
	 }
    if(maxi<a[i])
	   maxi=a[i];
	cout<<maxi<<" ";   
	if(inc!=0 && dec!=0)
	 {
	     if(inc>dec)
	      cout<<"4"<<endl;
	     else
	      cout<<"3"<<endl;
	 }
	else
	 {
	     if(dec==0)
	      cout<<"1"<<endl;
	     else
	      cout<<"2"<<endl;
	 }
    }
}