#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
	    long long int n,k,i,num,c=0;
	    cin>>n>>k;
	    vector<long long int> v;
	    for(i=0;i<n;i++)
	     {
	         cin>>num;
	         if(num<k)
	          {
	          // int temp=num;
	           v.push_back(num);
	          }
	     }
	    for(i=0;i<v.size();i++)
	     {
	         long long int q=v[i],mod,mod1,f=0;
	         while(q>9)
	          {
	              mod=q%10;
	              q/=10;
	              mod1=q%10;
	              if(abs(mod1-mod)!=1)
	               f=1;
	          }
	         if(f==0 && v[i]>9) 
	          {
	              c=1;
	              cout<<v[i]<<" ";
	          }
	     } 
	    if(c==0)
	     cout<<"-1";
	    cout<<endl; 
    }
}