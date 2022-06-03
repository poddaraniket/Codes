#include<bits/stdc++.h>
using namespace std;

void oddcount(int arr[],int n)
{
	int xoredval=0;
	for(int i=0;i<n;i++)
	 {
	 	xoredval^=arr[i];
	 }
	//xoredval has the xor val of both the number 
	int setval=xoredval & ~(xoredval-1); 
	// u get the right most set bt thta tell us that in this bit val was diff
	int x=0,y=0;
	for(int i=0;i<n;i++)
	 {
	 	if(arr[i] & setval)
	 	 x^=arr[i];
	 	else
	 	 y^=arr[i]; 
	 } 
	cout<<x<<" "<<y<<endl; 
}

int main()
{
	int arr[]={4, 2, 4, 5, 2, 3, 3, 1};
	int n=sizeof(arr)/sizeof(arr[0]);
	oddcount(arr,n);
}