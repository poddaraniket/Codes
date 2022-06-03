#include <bits/stdc++.h>
using namespace std;

int ans[1000][1000];
int arr[1000][1000];

void rotate(int n,int col)
{
    for(int i=0;i<n;i++) 
     {
        arr[i][col]^=1; 
     }
}

int count(int n,int m)
{
    int sum=0,temp=0;
    for(int i=0;i<n;i++)
     {
         int sum=0;
         for(int j=0;j<m;j++)
          {
             sum+=arr[i][j]; 
          }
         if(sum==m)
          temp++;
     }
    //cout<<temp<<endl; 
    return temp; 
}

void reinsert(int n,int m)
{
    for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++) 
         {
          ans[i][j]=arr[i][j];
         }
     }
}

void permute(int n,int m,int k,int &maxi)
{
    if(k==0)
     {
        int val=count(n,m); 
        if(maxi<val)
         {
            maxi=val;
            reinsert(n,m);
         }
        return; 
     }
    for(int i=0;i<m;i++)
     {
        rotate(n,i);
        permute(n,m,k-1,maxi);
        rotate(n,i);
     }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	     {
	        for(int j=0;j<m;j++)
	        {
	          cin>>arr[i][j];
	          
	        }
	     }
	    int k,maxi=0; 
	    cin>>k;
	    permute(n,m,k,maxi);
	    if(maxi>0)
	     {
	       cout<<maxi<<endl;  
	       for(int i=0;i<n;i++)
	        { 
	         for(int j=0;j<m;j++)
	          cout<<ans[i][j]<<" ";
	         cout<<endl; 
	        }
	     }
	    else
	     cout<<"0"<<endl;
	}
	return 0;
}
