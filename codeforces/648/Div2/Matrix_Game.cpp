#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,i,j;
	    cin>>n>>m;
	    int row[n]={0};
	    int col[m]={0};
	    int rowc=n,colc=m;
	    int a[n][m];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	         {
	             cin>>a[i][j];
	             if(a[i][j]==1)
	              {
	                  if(row[i]==0)
	                   {
	                       rowc--;
	                       row[i]=1;
	                   }
	                  if(col[j]==0)
	                   {
	                       colc--;
	                       col[j]=1;
	                   }
	              }
	         }
	    }
	   int mini=min(rowc,colc);
	   if(mini%2==0)
	     cout<<"Vivek"<<endl;
	   else
	     cout<<"Ashish"<<endl;
	}
	return 0;
}