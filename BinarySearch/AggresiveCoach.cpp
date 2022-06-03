#include <bits/stdc++.h>
using namespace std;


int n,k;
int fits(int num,int stalls[])
{
    //cout<<num<<endl;
    int pos=stalls[0],cows=1;
    for(int i=0;i<n;i++)
     {
        if(stalls[i]-pos>=num)
         {
            cows++;
            pos=stalls[i];
            if(cows==k)
            {
              //cout<<num<<endl;    
              return 1;
            }
         }
     }
    return 0; 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    //int n;
	    cin>>n>>k;
	    int stalls[n];
	    for(int i=0;i<n;i++)
	     cin>>stalls[i];
	    sort(stalls,stalls+n);
	    // binary search on gap 
	    int start=0,end=stalls[n-1]-stalls[0],mid,maxi=-1;
	    while(start<=end)
	    {
	        mid=(end+start)/2;
	        //int gap=mid-1;
	        if(fits(mid,stalls)==1)
	         {
	             maxi=max(maxi,mid);
	             start=mid+1;
	         }
	        else
	         end=mid-1;
	    }
	   cout<<maxi<<endl; 
	}
	return 0;
}
