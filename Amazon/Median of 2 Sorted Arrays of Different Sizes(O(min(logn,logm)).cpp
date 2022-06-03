#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int a[]={1,3,5,9};
	    int b[]={2,3,4,6};
	    int a_size=sizeof(a)/sizeof(a[0]);
	    int b_size=sizeof(b)/sizeof(b[0]);
	    double maxleftX,maxleftY,minrightY,minrightX;
	    int l=0,r=min(a_size,b_size)-1;
	    while(l<=r)
	    {
	        int partitionX=(l+r)/2;
	        /*
	          partitionX+partitionY=(SizeOfArray1+SizeOfArray2)/2; 
	          bcoz each partition should be equal to get the median in the middle
	        */
	        int partitionY=((a_size+b_size+1)/2)-partitionX;
	        /*
	        perfect partion would be such that max of left side is less than min of right side
	        */
	        maxleftX=a[partitionX-1];
	        minrightY=b[partitionY];
	        maxleftY=b[partitionY-1];
	        minrightX=a[partitionX];
	        if(maxleftX<=minrightY && maxleftY<=minrightX)
	         break;
	        else if(maxleftX>minrightY)
	         r=partitionX-1;
	        else
	         l=partitionX+1;
	    }
	   //cout<<a[0]<<endl; 
	   //cout<<maxleftX<<" "<<maxleftY<<" "<<minrightY<<" "<<minrightX<<endl;
	   if((a_size+b_size)%2==0)
	    {
	        //cout<<"*"<<endl;
	        cout<<(max(maxleftX,maxleftY)+min(minrightY,minrightX))/2.0<<endl;
	    }
	   else 
	    cout<<max(maxleftX,maxleftY)<<endl;
	}
	return 0;
}
