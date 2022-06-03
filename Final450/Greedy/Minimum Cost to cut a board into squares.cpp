#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
 {
     return a>b;
 }

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int vert[m-1];
	    int hor[n-1];
	    for(int i=0;i<m-1;i++)
	     cin>>vert[i];
	    for(int i=0;i<n-1;i++)
	     cin>>hor[i];
	    sort(vert,vert+m-1,cmp);
	    sort(hor,hor+n-1,cmp);
	    int ver=1,hori=1,v=0,h=0,cost=0;
	    while(v<m-1 && h<n-1)
	     {
	         if(vert[v]>hor[h])
	          {
	              cost+=(ver*vert[v]);
	              v++;
	              hori++;
	          }
	         else
	          {
	             cost+=(hori*hor[h]); 
	             h++;
	             ver++;
	          }
	     }
	   // int total=0; 
	    while(v<m-1)
	     {
	      //  total+=vert[v++]; 
	        cost+=(ver*vert[v]);
	        v++;
	        hori++; 
	     }
	   // cost+=(total*ver); 
	   // total=0; 
	    while(h<n-1)
	     {
	       // total+=hor[h++]; 
	        cost+=(hori*hor[h]);
	        h++;
	        ver++; 
	     }
	    //+=(total*hori); 
	    cout<<cost<<endl; 
	}
	return 0;
}
