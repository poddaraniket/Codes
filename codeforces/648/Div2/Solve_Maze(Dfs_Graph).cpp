#include <bits/stdc++.h>
using namespace std;
 
 
int n,m; 
int vis[52][52];
int block[52][52];
 
bool isValid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
     return false;
    return true; 
}
 
void dfs(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || block[i][j]==1)
     return;
    vis[i][j]=1;
    if(i<n-1)
     dfs(i+1,j);
    if(i>0)
     dfs(i-1,j);
    if(j<m-1)
     dfs(i,j+1);
    if(j>0)
     dfs(i,j-1);
}
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int i,j,flag=0;
	    cin>>n>>m;
	    char a[n][m];
	    memset(block,0,sizeof(block));
	    memset(vis,0,sizeof(vis));
	    for(i=0;i<n;i++)
	     {
	         for(j=0;j<m;j++)
	         {
	           cin>>a[i][j];
	         }
	     }
	    int x_dir[]={-1,+1,0,0};
	    int y_dir[]={0,0,-1,+1};
	    for(i=0;i<n;i++)
	     {
	         for(j=0;j<m;j++)
	          {
	              if(block[i][j]==0 && (a[i][j]=='#' || a[i][j]=='B'))
	               block[i][j]=1;
	              if(a[i][j]=='B')
	               {
	                   for(int k=0;k<4;k++)
	                     {
	                         int x=i+x_dir[k];
	                         int y=j+y_dir[k];
	                         if(isValid(x,y))
	                          {
	                              if(a[x][y]=='G')
	                              {
	                               flag=1;
	                              }
	                              else
	                               block[x][y]=1;
	                          }
	                     }
	                    
	               }
	          }
	     }
	   if(flag==1)
	    cout<<"No"<<endl;
	   else
	   {
	       int flag=0;
	       dfs(n-1,m-1);
	       for(i=0;i<n;i++)
	        {
	            for(j=0;j<m;j++)
	             {
	                 if(a[i][j]=='G' && vis[i][j]!=1)
	                  {
	                      flag=1;
	                      break;
	                  }
	             }
	            if(flag==1)
	             {
	                 cout<<"No"<<endl;
	                 break;
	             }
	        }
	       if(flag==0)
	        cout<<"Yes"<<endl;
	   }
	   // blocked all bad boys wayout
	}
	return 0;
}