#include <iostream>
#include<algorithm>
#include<cstdio>
//#include<Windows.h> 
using namespace std;  

int max_Books(int[], int, int);     
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  	int n,k;
  	cin>>n>>k;
  	int ar[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>ar[i];
  	}
        	cout<<max_Books(ar,n,k)<<endl;
        
  }    
  return 0;
}

// } Driver Code Ends


/*You are requried to complete this method */
int max_Books(int a[], int n, int k)
{
    // Your code here
    int maxi=0,sum=0;
    for(int i=0;i<n;i++)
     {
        if(a[i]<=k)
         sum+=a[i];
        else
        {
         maxi=max(sum,maxi);
         sum=0;
        }
     }
    maxi=max(maxi,sum); 
    return maxi; 
}