#include <bits/stdc++.h>
using namespace std;

int search(int b[],double x,int z)
{
    int l,r,mid;
    l=0;
    r=z-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(b[mid]<x)
         {
             if(b[mid+1]>x)
              {
                if((b[mid+1]-x)<=(x-b[mid]))
                 return b[mid+1];
                else
                 return b[mid];
              }
             else
               l=mid+1;
         }
        else if(b[mid]>x)
         {
             if(b[mid-1]<x)
              {
                  if((x-b[mid-1])<=(b[mid]-x))
                   return b[mid-1];
                  else
                   return b[mid];
              }
             else
              r=mid-1;
         }
        else
          return b[mid];
    }
 return b[mid];    
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int i,x,y,z,j,c=0,diff,min;
	    double find,ai,bi;
	    cin>>x>>y>>z;
	    int r[x],g[y],b[z];
	    for(i=0;i<x;i++)
	     cin>>r[i];
	    for(i=0;i<y;i++)
	     cin>>g[i];
	    for(i=0;i<z;i++)
	     cin>>b[i];
	    sort(r,r+x);
	    sort(g,g+y);
	    sort(b,b+z);
	   // cout<<r[0]<<g[0]<<b[0]<<endl;
	    min=abs(r[0]-g[y-1]);
	    ai=r[0];
	    bi=g[y-1];
	    i=1;
	    j=y-2;
	    while(i<x && j>=0)
	     {
	         diff=abs(r[i]-g[j]);
	        // cout<<diff<<endl;
	         if(min>diff)
	          {
	             min=diff;
	             ai=r[i];
	             bi=g[j];
	          }
	         else
	          {
	          // cout<<diff<<endl;   
	           c=1;   
	           break;
	          }
	         i++;
	         j--;
	     }
	    //cout<<ai+bi<<endl; 
	    if(c==0)
	     {
	       if(j>=0)
	         {
	           while(j>=0)
	             {
	               diff=abs(r[x-1]-g[j]);
	               if(min>diff)
	                 {
	                  min=diff;
	                  ai=r[x-1];
	                  bi=g[j];
	                 }
	               else
	                 break;
	                j--;
	               }
	          }
	         else if(i<x)
	           {
	             while(i<x)
	               {
	                  diff=abs(r[i]-g[0]);
	                  if(min>diff)
	                   {
	                       min=diff;
	                       ai=r[i];
	                       bi=g[0];
	                   }
	                  else
	                   break;
	                  i++;
	               }
	           }
	     }
	   find=(ai+bi)/2;
	   int t=search(b,find,z);
	   cout<<ai<<" "<<bi<<" "<<t<<endl;
	   long long int ans;
	   ans=((ai-bi)*(ai-bi))+((bi-t)*(bi-t))+((t-ai)*(t-ai));
	   cout<<ans<<endl;
	}
	return 0;
}