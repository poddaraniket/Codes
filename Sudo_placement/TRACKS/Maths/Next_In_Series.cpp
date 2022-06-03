#include <bits/stdc++.h>
using namespace std;

int AP(int a,int b,int c)
{
    if((b-a)==(c-b))
      return 1;
    return -1;  
}

int GP(int a,int b,int c)
{
    if(a!=0 && b!=0 && c!=0)
     {
        if(b%a==0 && c%b==0)
         {
             if((b/a)==(c/b))
              return 1;
         }
     }
    return -1; 
}

int Fibo(int a,int b,int c)
{
    if((a+b)==c)
     return 1;
    return -1; 
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,i,a=0,g=0,f=0,diff,mul;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++)
	     cin>>arr[i];
	    if(n>2)
	    {
	    for(i=1;i<n-1;i++)
	     {
	         if(a!=-1)
	           a=AP(arr[i-1],arr[i],arr[i+1]);
	         if(g!=-1)
	           g=GP(arr[i-1],arr[i],arr[i+1]);
	         if(f!=-1)    
	           f=Fibo(arr[i-1],arr[i],arr[i+1]);
	     }
	   // cout<<a<<" "<<g<<" "<<f<<endl; 
	    if(a==1)
	     cout<<arr[n-1]+(arr[n-1]-arr[n-2])<<endl;
	    else if(g==1)
	     cout<<arr[n-1]*(arr[n-1]/arr[n-2])<<endl;
	    else if(f==1)
	     cout<<arr[n-1]+arr[n-2]<<endl;
	    else
	     cout<<"-99999"<<endl;
	    }
	   else 
	     cout<<(arr[1]-arr[0])+arr[1]<<endl; 
	}
	return 0;
}