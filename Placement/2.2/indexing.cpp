#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		 cin>>a[i];
		long long int maxi=-1,diff;
		//int ans=-1;
		 for(long long int i=0;i<n;i++)
		  {
			  for(long long int j=i+1;j<n;j++)
			   {
				   if(a[j]>a[i])
                    {
						maxi=max(maxi,j-i);
					}
			   }
		  }
		 cout<<maxi<<endl; 
	}	
}