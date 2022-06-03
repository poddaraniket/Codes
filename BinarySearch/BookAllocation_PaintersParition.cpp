#include <bits/stdc++.h>
using namespace std;


int n,k;
int fits(int num,int pages[])
{
    //cout<<num<<endl;
    int students=1,sum=0;
    for(int i=0;i<n;i++)
     {
        if(pages[i]>num)
         return 0;
        if(pages[i]+sum>num)
         {
            students++;
            sum=pages[i];
            if(students>k)
             return 0;
         }
        else
         sum+=pages[i];
     }
    return 1; 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    //int n;
	    int end=0;
	    cin>>n>>k;
	    int pages[n];
	    for(int i=0;i<n;i++)
	    {
	     cin>>pages[i];
	     end+=pages[i];
	    }
	    sort(pages,pages+n);
	    // binary search on gap 
	    int start=pages[0],mid,mini=10000000;
	    while(start<=end)
	    {
	        mid=(end+start)/2;
	        //int gap=mid-1;
	        if(fits(mid,pages)==1)
	         {
	             mini=min(mini,mid);
	             end=mid-1;
	         }
	        else
	         start=mid+1;
	    }
	   cout<<mini<<endl; 
	}
	return 0;
}
