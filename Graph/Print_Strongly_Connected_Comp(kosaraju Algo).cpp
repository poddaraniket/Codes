/*
As per this algo if you reverse the grpah direction or take a transpose of this graph the strongly connected components remain the same
So you traverse the graph twice first traverse and store it in the stack then reverse the direction and using stack print the components
by traversing the reverse graph in same way as don in first traverse
*/ 
//O(E+V)

#include <bits/stdc++.h>
using namespace std;

//stack<int> s;

void addEdge(vector<int> adj[],vector<int> adj_rev[],int u,int v)
{
    adj[u].push_back(v);
    adj_rev[v].push_back(u);
}


// it creates the stack in the first travserse
void DFS(vector<int> adj[],int u,bool vis[],stack<int> &s)
{
    //int flag=0;
    vis[u]=true;
    //cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++)
     {
        if(vis[adj[u][i]]==false)
        {
         // flag=1;  
          DFS(adj,adj[u][i],vis,s);
        }
        else
         continue;
     }
   s.push(u);
}

// using the stack and reversed direction of graph print all the strongly connecetd comp

void DFSUtil(vector<int> adj_rev[],int u,bool vis[],vector<int> &v)
{
    v.push_back(u);
    vis[u]=true;
    for(int i=0;i<adj_rev[u].size();i++)
     {
        if(vis[adj_rev[u][i]]==false)
         DFSUtil(adj_rev,adj_rev[u][i],vis,v);
     }
}

int main() {
	// your code goes here
	vector<int> adj[11],adj_rev[11];
	addEdge(adj,adj_rev,0,2);
	addEdge(adj,adj_rev,2,1);
	addEdge(adj,adj_rev,1,0);
	addEdge(adj,adj_rev,2,3);
	addEdge(adj,adj_rev,3,4);
	addEdge(adj,adj_rev,4,5);
	addEdge(adj,adj_rev,5,3);
	addEdge(adj,adj_rev,6,5);
	addEdge(adj,adj_rev,6,7);
	addEdge(adj,adj_rev,7,8);
	addEdge(adj,adj_rev,8,9);
	addEdge(adj,adj_rev,9,6);
	addEdge(adj,adj_rev,9,10);
	
	bool vis[11];
	memset(vis,false,sizeof(vis));
	stack<int> s;
	for(int i=0;i<11;i++)
	  {
	     if(vis[i]==false)
	       DFS(adj,i,vis,s);
	  }
	memset(vis,false,sizeof(vis)); 
	vector<int> v;
	while(!s.empty())
	{
	  if(vis[s.top()]==false)  
	   DFSUtil(adj_rev,s.top(),vis,v);
	  if(v.size()>0)
	   {
	       for(int i=0;i<v.size();i++)
	        cout<<v[i]<<" ";
	       cout<<endl; 
	       v.clear(); 
	   }
	  s.pop(); 
	}
	return 0;
}
