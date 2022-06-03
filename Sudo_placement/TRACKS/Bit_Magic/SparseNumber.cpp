#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i=1,mask=1,c=0,flag=0;
	    cin>>n;
	    while(i<=10)
	     {
	        if(n&mask) 
	         c++;
	        else
	         c=0;
	        if(c==2)
	         {
	          flag=1;
	          break;
	         }
	        i++; 
	        mask<<=1;
	     }
	    if(flag==0) 
	     cout<<"1"<<endl;
	    else
	     cout<<"0"<<endl;
	}
	return 0;
}