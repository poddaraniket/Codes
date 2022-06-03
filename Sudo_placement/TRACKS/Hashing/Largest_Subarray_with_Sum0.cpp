#include<bits/stdc++.h>

using namespace std;

int maxLen(int A[], int n) {
    // Your code here
    int B[n];
    unordered_map<int,int> mp;
    B[0]=A[0];
    mp[B[0]]=1;
    for(int i=1;i<n;i++)
    {
        B[i]=B[i-1]+A[i];
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
       if(B[i]==0)
        maxi=i+1;
       else
        {
         if(mp[B[i]]==0)
          {
            mp[B[i]]=i+1;
          } 
         else
          {
                maxi=max(maxi,i+1-mp[B[i]]); 
          } 
        }
    }
    return maxi;
}

int main()
{
	int t;
	cin>>t
	while(t--)
	{
	  int n;
	  cin>>n;
	  int a[n];
	  for(int i=0;i<n;i++)
	   {
	    cin>>a[i];
	   }
      cout<<maxLen(a,n)<<endl;
	}
}