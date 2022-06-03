#include <bits/stdc++.h>
using namespace std;

//stack<int> s;



// it creates the stack in the first travserse
void DFS(vector<int> adj[],int u,bool vis[],int indeg[],int outdeg[])
{
    //int flag=0;
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
     {
        if(vis[adj[u][i]]==false)
        {
         // flag=1;
          outdeg[u]=1;
          indeg[adj[u][i]]=1;
          DFS(adj,adj[u][i],vis,indeg,outdeg);
        }
     }
}

void addEdge(int src[],int dest[],int V,int E)
{
    vector<int> adj[V];
    for(int i=0;i<E;i++)
     {
        adj[src[i]].push_back(dest[i]); 
     }
    //cout<<"*"<<endl; 
    int indeg[V]={0};
	int outdeg[V]={0};
	bool vis[V];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<V;i++)
	  {
	     if(vis[i]==false)
	       DFS(adj,i,vis,indeg,outdeg);
	  }
	int total_in=0,total_out=0;  
    for(int i=0;i<V;i++)
     {
        if(indeg[i]>0)
          total_in++;
        if(outdeg[i]>0)
         total_out++;
     }
    cout<<max(V-total_in,V-total_out)<<endl; 
}


int main() {
	// your code goes here
	 int N = 6, M = 5; 
  
    int source[] = { 1, 3, 1, 3, 5 }; 
    int destination[] = { 2, 2, 3, 5, 6 };
    
    addEdge(source,destination,N,M);
	
	return 0;
}
