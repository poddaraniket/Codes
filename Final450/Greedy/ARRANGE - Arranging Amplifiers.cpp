// x^y if(try to keep y bigger the value will come bigger so descending)
// exceptions : 1. if we have 2 3 
//              2. if we have 1s at the end 

#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
 {
     return a>b;
 }

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n],ones=0;
	    for(int i=0;i<n;i++)
	    {
	     cin>>arr[i];
	     if(arr[i]==1)
	      ones++;
	    }
        sort(arr,arr+n,cmp);
        for(int i=0;i<ones;i++)
         cout<<"1 ";
        if(n-ones==2 && arr[0]==3 && arr[1]==2)
         cout<<"2 3"<<endl;
        else
         {
            for(int i=0;i<n-ones;i++)
             cout<<arr[i]<<" ";
         }
        cout<<endl; 
	}
	return 0;
}
