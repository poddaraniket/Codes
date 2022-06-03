#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int m,n,temp,i;
	string maxsum="",minsum="";
	cin>>m>>n;
	int min[m]={0},max[m]={0};
	temp=n-1;
	if(n>0)
	{
	    for(i=m-1;i>0;i--)
	    {
	        if(temp>9)
	        {
	         min[i]=9;
	         temp-=9;
	        }
	        else
	        {
	          min[i]=temp;
	          temp=0;
	          break;
	        }
	    }
	    if(temp>9)
	       cout<<"-1"<<" -1"<<endl;
	    else
	      {
	        min[0]=temp+1;
	        for(i=0;i<m-1;i++)
	        {
	          if(n>9)
	           {
	            max[i]=9;
	            n-=9;
	           }
	          else
	          {
	            max[i]=n;
	            n=0;
	            break;
	          }
	       }
	     if(n>9)
	       cout<<"-1"<<" -1"<<endl;
	     else
	     {
	       max[m-1]=n;
	       for(i=0;i<m;i++)
	         {
	            maxsum+=to_string(max[i]);
	            minsum+=to_string(min[i]);
	         }
	       cout<<minsum<<" "<<maxsum<<endl;  
	     }
      }
	}  
	else
	 {
	     if(n==0 && m>1)
	       cout<<"-1"<<" -1"<<endl;
	     else
	       cout<<"0"<<" 0"<<endl;
	 }
	return 0;
}