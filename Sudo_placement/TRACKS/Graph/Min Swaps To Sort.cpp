// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int N){
    /*Your code here */
    if(N==1)
     return 0;
    vector<pair<int,int>> v(N);
    for(int i=0;i<N;i++)
     {
        v[i].first=arr[i];
        v[i].second=i;
     }
    sort(v.begin(),v.end());
    vector<bool> vis(N, false); 
    int count=0;
    for(int i=0;i<N;i++)
     {
        if(vis[i] || v[i].second==i)
          continue;
        int j=i;
        int cycle_size=0;
        while(!(vis[j]))
         {
            vis[j]=true;
            cycle_size++;
            j=v[j].second;
         }
        if(cycle_size>0)
         count+=(cycle_size-1);
     }
    return count; 
}
