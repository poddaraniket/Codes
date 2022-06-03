// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int G[MAX][MAX];
	while(t--)
	{
		memset(G,0,sizeof (G));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>G[i][j];
			}
		}
		
		cout<<isBipartite(G,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

bool BFS(int G[][MAX],int V,int src,int color[])
{
    queue<int> q;
    q.push(src);
    while(!q.empty())
     {
        int u=q.front();
        q.pop();
        if(G[u][u]==1)
         return false;
        for(int v=0;v<V;v++)
         {
            if(G[u][v]==1 && color[v]==-1)
            {
             color[v]=1-color[u];
             q.push(v);
            }
            else if(G[u][v]==1 && color[v]==color[u])
             return false;
         }
     }
    return true; 
}

bool isBipartite(int G[][MAX],int V)
{
     //Your code here
     int color[V];
     memset(color,-1,sizeof(color));
     for(int i=0;i<V;i++)
     {
        if(color[i]==-1)
        {
          if(!BFS(G,V,i,color))
           return false;
        }
     }
     return true;
}