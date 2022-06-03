#include <bits/stdc++.h>
using namespace std;

int countsetBits(int num)
{
    int i,mask=1,c=0;
    for(i=0;i<=31;i++)
     {
         if(mask&num)
          c++;
         mask<<=1; 
     }
    return c; 
}

int main() {
	// your code goes here
int t;
	cin>>t;
	while(t--)
	{
	    int n,t,flag=0;
	    cin>>n;
	    t=ceil(log2(n));
	
	    //temp=t;
	    while(t)
	    {
	        if(n>t)
	         {
	           //count=n-t;
	           int x=countsetBits(n-t);
	           if(x==t)
	            {
	                flag=1;
	                break;
	            }
	         }
	        t--; 
	    }
	   if(flag==1)
	    cout<<"0"<<endl;
	   else
	    cout<<"1"<<endl;
	}
	return 0;
}
