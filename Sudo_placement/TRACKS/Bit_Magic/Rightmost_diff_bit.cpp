
#include<bits/stdc++.h>
using namespace std;

int s,n;
int a[30];

int xor_remove(int x)
{
    if(x==-1)
     return s;
    return s^a[x];
}

int main() {
	int t;
	cin>>t;
	while(t--)
	 {
	    int n,m,i,c=0,mask=1;
	    cin>>n>>m;
	    for(i=0;i<=31;i++)
	     {
	        int x= n&(mask<<i);
	        int y= m&(mask<<i);
	        if(x!=y)
	         {
	             c=1;
	             break;
	         }
	     }
	    if(c==1)
	     cout<<i+1<<endl;
	    else
	     cout<<"-1"<<endl;
	 }
}