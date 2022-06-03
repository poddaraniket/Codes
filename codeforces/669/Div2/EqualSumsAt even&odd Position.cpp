#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n],cnt1=0,cnt0=0;
	    for(int i=0;i<n;i++)
	     {
	         cin>>arr[i];
	         if(arr[i]==1)
	          cnt1++;
	         else
	          cnt0++;
	     }
	    if(cnt1>(n/2))
	     {
	         if(cnt1%2!=0)
	          cnt1--;
	         cout<<cnt1<<endl; 
	         for(int i=0;i<cnt1;i++)
	          cout<<"1"<<" ";
	     }
	    else
	     {
	         cout<<cnt0<<endl;
	         for(int i=0;i<cnt0;i++)
	          cout<<"0"<<" ";
	     }
	    cout<<endl; 
	}
	return 0;
}