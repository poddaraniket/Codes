#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   int n,i,j,k,s=0,c=0,g,h,l;
	   cin>>n;
	   if(n<=10)
	    {
	        if(n==8)
	         cout<<"Yes"<<endl;
	        else
	         cout<<"No"<<endl;
	    }
	   else
	   {
	   vector<int> v;
	   while(n)
	    {
	       v.push_back(n%10);
	       n/=10;
	    }
	   for(i=0;i<v.size();i++)
	   {
	       if(v[i]==0)
	        continue;
	       g=(s*10)+v[i];
	       //cout<<g<<endl;
	       for(j=0;j<v.size();j++)
	        {
	            if(j!=i)
	             { 
	              h=(g*10)+v[j];
	              //cout<<h<<endl;
	              if(v.size()>=3)
	               {
	               for(k=0;k<v.size();k++)
	                {
	                 if(k!=j && k!=i)
	                 {
	                  l=(h*10)+v[k];
	                  if(l%8==0)
	                    {
	                      //cout<<l<<endl;
	                      c=1;
	                      break;
	                    }
	                  }//s/=10; 
	                }
	               }
	              else
	               {
	                   if(h%8==0)
	                    {
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
	  
	}
	return 0;
}