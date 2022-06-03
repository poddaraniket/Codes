#include <bits/stdc++.h>
using namespace std;

int maxi=0;

void maxArea(int a[],int len,int l,int r)
{
    if(l==r)
     return;
    maxi=max(maxi,min(a[l],a[r])*(r-l)); 
    maxArea(a,len-1,l+1,r);
    maxArea(a,len-1,l,r-1);

    /*
      Iterative Approach
      while(l<r)
       {
	     maxi=max(maxi,min(l,r)*(r-l));
	     if(a[l]<a[r])
	      l++;
	     else
	      r--; 
       }
    */
    //maxArea(a,len-2,l-1,r-1);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	   int a[] = {3, 1, 2, 4, 5};
	   int n=sizeof(a)/sizeof(a[0]);
	   maxArea(a,n-1,0,n-1);
	   cout<<maxi<<endl;
	}
	return 0;
}
