#include <bits/stdc++.h>
using namespace std;

long long int lookup[101][1001]={-1}; 

long long int rec(int n,int sum)
{
  int i;
   long long int ans=0;
  if(n==0)
   {
    // sum=0;
    return sum==0;
   }
  if(lookup[n][sum]!=-1)
   {
       return lookup[n][sum];
   }
   for(i=0;i<=9;i++)
    {
      if(sum-i>=0)
        ans+=(rec(n-1,sum-i)%1000000007);
    }
   lookup[n][sum]=ans%1000000007;
   return lookup[n][sum];
}

long long int finalcount(int n,int sum)
{
    for(int i=0;i<=100;i++)
     {
         for(int j=0;j<=1000;j++)
          lookup[i][j]=-1;
     }
    long long int ans=0;
    int i;
    for(i=1;i<=9;i++)
     {
        if(sum-i>=0) 
         ans+=(rec(n-1,sum-i)%1000000007); 
     }
    return ans%1000000007; 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	   int n,sum;  
       cin>>n>>sum;
       long long int t;
       t=finalcount(n,sum);
       if(t==0)
        cout<<"-1"<<endl;
       else
        cout<<t<<endl;
	 }
	return 0;
}
