
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int i,n,j,c=0;
	    vector<int>one,zero;
	    cin>>n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	     {
	         cin>>a[i];
	         if(a[i]%2==0)
	          zero.push_back(a[i]);
	         else
	          one.push_back(a[i]);
	     }
	    if(zero.size()%2==0)
	     cout<<"YES"<<endl;
	    else
	     {
	         for(i=0;i<one.size();i++)
	          {
	              for(j=0;j<zero.size();j++)
	               {
	                   if(abs(one[i]-zero[j])==1)
	                    {
	                        c=1;
	                        break;
	                    }
	               }
	          }
	         if(c==1)
	          cout<<"YES"<<endl;
	         else
	          cout<<"NO"<<endl;
	     }
	}
	return 0;
}