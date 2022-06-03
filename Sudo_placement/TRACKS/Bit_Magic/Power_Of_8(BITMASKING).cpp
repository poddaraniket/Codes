#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,mask=1,i=1,flag=0;
	    cin>>n;
	    while(i<=60)
	    {
	     mask<<=3;     
	     if(!(n&(~mask)))   
	       {
	           flag=1;
	           break;
	       } 
	     i++;   
	    }
	   if(flag==1)
	    cout<<"Yes"<<endl;
	   else
	    cout<<"No"<<endl;
	}
	return 0;
}