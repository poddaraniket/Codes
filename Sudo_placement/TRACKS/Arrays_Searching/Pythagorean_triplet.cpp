#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     long long int a[1001]={0};
	     long long int n,i,c=0,j,num;
	     cin>>n;
	   //  int a[n];
	     for(i=0;i<n;i++)
	      {
	       cin>>num;
	       a[num]++;
	      }
	    for(i=1;i<1000;i++)
	     {
	         for(j=i+1;j<=1000;j++)
	          {
	              if(a[i]!=0 && a[j]!=0)
	               {
	                   long long int t=(i*i)+(j*j);
	                   if(ceil(sqrt(t))==floor(sqrt(t)))
	                    {
	                      long long int p=sqrt(t);  
	                      //cout<<p<<endl;
	                      if(a[p]>0)
	                      {
	                         //cout<<a[i][1]<<" "<<a[j][1]<<" "<<p<<endl; 
	                        //cout<<it->first<<" "<<it1->first<<" "<<sqrt(t)<<endl;    
	                        c=1;
	                        break;
	                      }
	                    }
	               }
	          }
	        if(c==1)
	         break;
	     }
	    if(c==1)
	     cout<<"Yes"<<endl;
	    else
	     cout<<"No"<<endl; 
	 }
	return 0;
}
